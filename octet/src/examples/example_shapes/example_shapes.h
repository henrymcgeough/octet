////////////////////////////////////////////////////////////////////////////////
//
// (C) Andy Thomason 2012-2014
//
// Modular Framework for OpenGLES2 rendering on multiple platforms.
//
namespace octet {
  /// Scene containing a box with octet.
  class example_shapes : public app {
    // scene for drawing box
    ref<visual_scene> app_scene;

  public:
    example_shapes(int argc, char **argv) : app(argc, argv) {
    }

    ~example_shapes() {
    }

// #define CF_KINEMATIC_OBJECT = 2
	enum CollisionFlags
	{
		CF_STATIC_OBJECT = 1,
		CF_KINEMATIC_OBJECT = 2,
		CF_NO_CONTACT_RESPONSE = 4,
		CF_CUSTOM_MATERIAL_CALLBACK = 8,//this allows per-triangle material (friction/restitution)
		CF_CHARACTER_OBJECT = 16,
		CF_DISABLE_VISUALIZE_OBJECT = 32, //disable debug drawing
		CF_DISABLE_SPU_COLLISION_PROCESSING = 64//disable parallel/SPU processing
	};

	enum	CollisionObjectTypes
	{
		CO_COLLISION_OBJECT = 1,
		CO_RIGID_BODY = 2,
		///CO_GHOST_OBJECT keeps track of all objects overlapping its AABB and that pass its collision filter
		///It is useful for collision sensors, explosion objects, character controller etc.
		CO_GHOST_OBJECT = 4,
		CO_SOFT_BODY = 8,
		CO_HF_FLUID = 16,
		CO_USER_TYPE = 32,
		CO_FEATHERSTONE_LINK = 64
	};

    /// this is called once OpenGL is initialized
    void app_init() {
      app_scene =  new visual_scene();
      app_scene->create_default_camera_and_lights();
      app_scene->get_camera_instance(0)->get_node()->translate(vec3(0, 4, 0));

      material *red = new material(vec4(1, 0, 0, 1));
      material *green = new material(vec4(0, 1, 0, 1));
      material *blue = new material(vec4(0, 0, 1, 1));

      mat4t mat;
      mat.loadIdentity();
      mat.translate( -10, 6, 0);
      std::vector<mesh_instance*> logs;
	    for (int i = 0; i != 10; ++i) {
  	    auto log = app_scene->add_shape(mat, new mesh_cylinder(zcylinder(vec3(0, 0, 0), 0.5, 4)), blue, true);
        logs.push_back(log);
        mat.translate(2, 0, 0);
      }

      // check out bullet stuff for kinematic objects
		logs[0]->get_node()->get_rigid_body()->setCollisionFlags(CF_KINEMATIC_OBJECT);
		logs.back()->get_node()->get_rigid_body()->setCollisionFlags(CF_KINEMATIC_OBJECT);

      for (int i = 0; i != 10-1; ++i) {
        auto a = logs[i];
        auto b = logs[i+1];
        // try adding a hinge between a and b
        // try to get app_scene->world
        // make a btHingeConstraint
        auto rba = a->get_node()->get_rigid_body();
        auto rbb = b->get_node()->get_rigid_body();
        //auto cstr = new btHingeConstraint(*rba, *rbb, btVector3(0.2f,0.8f,0), btVector3(0.2f,0.8f,0));
        //app_scene->get_world()->addConstraint(cstr); */
		
		btPoint2PointConstraint* leftSpring = new btPoint2PointConstraint(*rba, *rbb, btVector3(-0.5, 0, -0.5), btVector3(0.5, 0, -0.5));
		app_scene->get_world()->addConstraint(leftSpring);

		btPoint2PointConstraint* rightSpring = new btPoint2PointConstraint(*rba, *rbb, btVector3(-0.5, 0, 0.5), btVector3(0.5, 0, 0.5));
		app_scene->get_world()->addConstraint(rightSpring);

      }

      // ground
      mat.loadIdentity();
      mat.translate(0, -1, 0);
      app_scene->add_shape(mat, new mesh_box(vec3(200, 1, 200)), green, false);
    }

    /// this is called to draw the world
    void draw_world(int x, int y, int w, int h) {
      int vx = 0, vy = 0;
      get_viewport_size(vx, vy);
      app_scene->begin_render(vx, vy);

      // update matrices. assume 30 fps.
      app_scene->update(1.0f/30);

      // draw the scene
      app_scene->render((float)vx / vy);
    }
  };
}

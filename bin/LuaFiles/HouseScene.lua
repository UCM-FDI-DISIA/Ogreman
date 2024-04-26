Entities={
    {
        name = "Player",
        components = {
            {
                name = "TransformComponent",
                parameters = {  
                    position = {0, 0, 0},
                    rotation ={0, 0, 0},
                    scale = {1, 1, 1}                   
                }
            },
            {
                name = "MovementComponent",
                parameters = {                  
                    
                }
            },
            {
                name = "CameraComponent",
                parameters = {                  
                    name = "anim",
                    color = {1, 0, 0},
                    alfa = 0,
                    offset = {0, 0, 0}
                }
            },   
            {
                name = "PlayerInputComponent",
                parameters = {                  
                    
                }
            },     
            {
                name = "LightComponent",
                parameters = {
                    type = 1,
                    diffusecolour = {1, 1, 1},
                    shadowfardist = 25,
                    shadowdist = 25,
                    ineerangle = 90,
                    outerangle = 180,
                    nearclipdist = 0.1,
                    shdws = true
                }
	        },
            {
                name = "ColliderComponent",
                parameters = {
                }
            },
            -- {
            --     name = "RigidbodyComponent",
            --     parameters = {
            --         shapeType = 1,
            --         movementType = 0,
            --         size = {1, 1, 1},
            --         mass = 0,
            --         friction = 0,
            --         restitution = 0,
            --         trigger = true,
            --         mask = 1,
            --         group = 2
            --     }
            -- }                   
        }
    }, 
    {  
        name = "Light",
        components = {
	        {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {0, 0, 60},
                    rotation = {0, 0, 0},
                    scale = {1, 1, 1}                   
                }
            },
            {
                name = "LightComponent",
                parameters = {
                    type = 1,
                    diffusecolour = {1, 1, 1},
                    shadowfardist = 25,
                    shadowdist = 100,
                    ineerangle = 90,
                    outerangle = 180,
                    nearclipdist = 0.1,
                    shdws = true
                }
	        }     
        }
    }, 
    {
        name = "Ogreman",
        components = {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {0, 0, 0},
                    rotation = {0, 0, 0},
                    scale = {1, 1, 1}                   
                }
            },
            {
                name = "MeshRenderComponent",
                parameters = {                  
                    isstatic = false,
                    modelname = "Sinbad.mesh",
                    entityname= "sinbad",
                    materialname = ""
                }
            },
            {
                name = "ColliderComponent",
                parameters = {
                }
            },
            {
                name = "RigidbodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 1,
                    size = {2, 2, 2},
                    mass = 1,
                    friction =1,
                    restitution=1,
                    trigger = true,
                    mask = 1,
                    group = 1
                }
            }   
        }
    },
    {  
        name = "NODE1",
        components = {
	        {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {10, 0, 20},
                    rotation = {0, 0, 0},
                    scale = {0.5, 0.5, 0.5}                   
                }
            },
            {
                name = "MeshRenderComponent",
                parameters = {                  
                    isstatic = true,
                    modelname = "Sinbad.mesh",
                    entityname= "NODE",
                    materialname = ""
                }
	        },
            {
                    name="RigidBodyComponent",
                    parameters={
                        shapeType=0,
                        mass=0,
                        friction=0,
                        restitution=0,
                        movementType=1,
                        trigger=true,
                        size={2,2,2},
                        mask=0,
                        group=0


                    }
            },
            {
                    name="NodeComponent",
                    parameters={
                        ispatrol=true,
                        cost=1.1,
                        hcost=1.1,
                        iswalkable=true,
                        id=0

                    }
            }  

        }
    }, 

    {
        name = "Casa:)",
        components = {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {10, 0, 20},
                    rotation = {0, 0, 0},
                    scale = {5, 5, 5}                   
                }
            },
            {
                name = "MeshRenderComponent",
                parameters = {                  
                    isstatic = false,
                    modelname = "Casa.mesh",
                    entityname= "sinbad2",
                    materialname = ""
                }
            },
           
        }
    }
    
}
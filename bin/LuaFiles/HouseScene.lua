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
        name = "Ogreman2",
        components = {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {20, 0, 0},
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
                    materialname = "Sinbad/Gold"
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
            },
             {
                name="NodeComponent",
                parameters={
                    ispatrol=true,
                    cost=1.8,
                    hcost=1.8,
                    iswalkable=true,
                    id=0

                }
            }

        }
    },
    {
        name = "Ogreman3",
        components = {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {40, 0, 0},
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
                    materialname = "Sinbad/Gold"
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
            },
            {
                name="NodeComponent",
                parameters={
                    ispatrol=true,
                    cost=1.8,
                    hcost=1.8,
                    iswalkable=true,
                    id=0

                }

            },
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
                    movementType = 0,
                    size = {2, 2, 2},
                    mass = 1,
                    friction =1,
                    restitution=1,
                    trigger = true,
                    mask = 1,
                    group = 1
                }
            },
            {
                name="AnimatorComponent",
                parameters={
                    name="skeleton.mesh"
                }
            },
            {
                name="OgremanMovementComponent",
                parameters={

                }
            },
            
    
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
                name="GridComponent",
                parameters={

                }
            }
           
        }
    }
    
}
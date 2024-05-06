Entities={
    {
        name = "Player",
        components = {
            {
                name = "TransformComponent",
                parameters = {  
                    position = {20, 6, 50},
                    rotation ={0, 0, 0},
                    scale = {1, 1, 1}                   
                }
            },
           
            {
                name = "CameraComponent",
                parameters = {                  
                    name = "anim",
                    color = {1, 0, 0},
                    alfa = 0.0,
                    offset = {0, 0, 0},
                    zOrder = 1
                }
            },   
            {
                name = "LightComponent",
                parameters = {
                    type = 1,
                    diffusecolour = {1, 1, 1},
                    shadowfardist = 25.0,
                    shadowdist = 25.0,
                    ineerangle = 90.0,
                    outerangle = 180.0,
                    nearclipdist = 0.1,
                    shdws = true
                }
	        },
            {
                name = "ColliderComponent",
                parameters = {
                }
            },
            {
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 0,
                    size = {2, 6, 2},
                    mass = 10.0,
                    friction = 0.5,
                    restitution = 0.0,
                    trigger = false,
                    mask = 2,
                    group = 1
                }
            },
            {
                name = "MovementComponent",
                parameters = {                  
                    
                }
            },                
            {
                name = "UITransformComponent",
                parameters = {    
                    position = { 0.0,0.0},   
                    scale = { 0.11,0.1},   
                    hidden = false   
         
                }
            },
            {
                name = "UIProgressBarComponent",
                parameters = {             
                    maximo = 100.0,
                    progres = 100.0,
                    progressBarName = "p",
                    frameMaterial = "FlashLigt",
                    contentMaterial = "FlashLigtContent",
                    zOrder = 1                   
                }
            },
            {
                name = "PlayerInputComponent",
                parameters = {                  
                    
                }
            }, 
            {
                name = "FlashlightComponent",
                parameters = {                  
                    
                }
            }, 
            {
                name = "DesactiveUIComponent",
                parameters = {                  
                    
                }
            },
           
            {
                name = "PlayerInteractionComponent",
                parameters = {                  
                    
                }
            },
       
            {
                name = "PickUpComponent",
                parameters = {                  
                    
                }
            },
            
            {
                name = "RangosVisionComponent",
                parameters = {                  
                    maxv = 50.0, 
                    minv = 0.1,
                    maxt = 1.0, 
                    mint = 0.2
                }
            },
  
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
                    shadowfardist = 25.0,
                    shadowdist = 100.0,
                    ineerangle = 90.0,
                    outerangle = 180.0,
                    nearclipdist = 0.1,
                    shdws = true
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
                    position = {10, 0, 70},
                    rotation = {0, 0, 0},
                    scale = {5, 5, 5}                   
                }
            },
           
            {
                name="GridComponent",
                parameters={

                }
            },
            -- {
            --     name = "MeshRenderComponent",
            --     parameters = {                  
            --         isstatic = false,
            --         modelname = "Casa.mesh",
            --         entityname= "casa",
            --         materialname = ""
            --     }
            -- },
        }
    },  
    {
        name = "SueloCollider",
        components = 
        {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {0, -28, 0},
                    rotation = {0, 0, 0},
                    scale = {1, 1, 1}                   
                }
            },
            
            {
                name = "ColliderComponent",
                parameters = {
                }
            },
            {
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 1,
                    size = {200, 20, 200},
                    mass = 100000.0,
                    friction =10.0,
                    restitution=0.0,
                    trigger = false,
                    mask = 1,
                    group = 2
                }
            },
        }
    },
    {
        name = "NPC1",
        components = {
            {
                name = "TransformComponent",
                parameters = {  
                    position = {20, 0, 0},
                    rotation ={0, 0, 0},
                    scale = {10, 10, 10}                   
                }
            },
           
           
            {
                name = "LightComponent",
                parameters = {
                    type = 1,
                    diffusecolour = {1, 1, 1},
                    shadowfardist = 25.0,
                    shadowdist = 25.0,
                    ineerangle = 90.0,
                    outerangle = 180.0,
                    nearclipdist = 0.1,
                    shdws = true
                }
	        },
            {
                name = "ColliderComponent",
                parameters = {
                }
            },
            {
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 0,
                    size = {2, 6, 2},
                    mass = 10.0,
                    friction = 0.5,
                    restitution = 0.0,
                    trigger = false,
                    mask = 2,
                    group = 1
                }
            },
            {
                name = "MovementComponent",
                parameters = {                  
                    
                }
            },     
            {
                name = "MeshRenderComponent",
                parameters = {                  
                    isstatic = false,
                    modelname = "lagartija.mesh",
                    entityname= "NPC1",
                    materialname = " "
                    }
            },
            {
                name= "MerodeoMovementComponent",
                parameters={

                    }
            }
        }
    }
}
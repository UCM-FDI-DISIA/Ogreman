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
                    color = {0, 0, 0},
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
                    frameMaterial = "Sinbad/Gold",
                    contentMaterial = "Sinbad/Gold",
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
        name = "Pila",
        components = {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {20, -5, 20},
                    rotation = {0, 0, 180},
                    scale = {5, 5, 5}                   
                }
            },
            {
                name = "MeshRenderComponent",
                parameters = {                  
                    isstatic = false,
                    modelname = "Pila.mesh",
                    entityname= "pila",
                    materialname = ""
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
                    size = {5, 5, 5},
                    mass = 1.0,
                    friction =1.0,
                    restitution=1.0,
                    trigger = false,
                    mask = 1,
                    group = 2
                }
            },
            {
                name = "UITransformComponent",
                parameters = {
                    pos = {0.0, 0.0}, 
                    scale= {1.0, 1.0 }, 
                    hidden = true
                }
            },
            {
                
                name = "UISpriteRendererComponent",
                parameters = {
                    name = "nombree", 
                    material = "Sinbad/Gold", 
                    zOrder = 1
                }
            },
            {
                name = "CellComponent",
                parameters = {
                  
                }
            }
            
        }
    },
    {
        name = "NotaPrueba",
        components = {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {40, -5, 20},
                    rotation = {0, 0, 180},
                    scale = {5, 5, 5}                   
                }
            },
            {
                name = "UITransformComponent",
                parameters = {
                    pos = {0.0, 0.0}, 
                    scale= {1.0, 1.0 }, 
                    hidden = true
                }
            },
            {
                
                name = "UISpriteRendererComponent",
                parameters = {
                    name = "notaPrueba", 
                    material = "Sinbad/Gold", 
                    zOrder = 1
                }
            },
            {
                name = "ShowImageComponent",
                parameters = {
                    ttoshow = 5.0
                }
            }
            
        }
    },
    {
        name = "Nota",
        components = {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {40, -5, 20},
                    rotation = {0, 0, 180},
                    scale = {5, 5, 5}                   
                }
            },
            {
                name = "MeshRenderComponent",
                parameters = {                  
                    isstatic = false,
                    modelname = "Pila.mesh",
                    entityname= "nota",
                    materialname = "Pila.material"
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
                    size = {5, 5, 5},
                    mass = 1.0,
                    friction =1.0,
                    restitution=1.0,
                    trigger = false,
                    mask = 1,
                    group = 2
                }
            },
            {
                name = "UITransformComponent",
                parameters = {
                    pos = {0.0, 0.0}, 
                    scale= {1.0, 1.0 }, 
                    hidden = true
                }
            },
            {
                
                name = "UISpriteRendererComponent",
                parameters = {
                    name = "notac", 
                    material = "Sinbad/Gold", 
                    zOrder = 1
                }
            },
            {
                name = "NoteComponent",
                parameters = {
                    text = "NotaPrueba"
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
                    position = {10, 0, 0},
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
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 2,
                    size = {2, 2, 2},
                    mass = 1.0,
                    friction =1.0,
                    restitution=1.0,
                    trigger = true,
                    mask = 1,
                    group = 2
                }
            },
             {
                name="NodeComponent",
                parameters={
                    ispatrol=true,
                    cost=1.8,
                    hcost=1.8,
                    iswalkable=true,
                    id=1

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
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 2,
                    size = {2, 2, 2},
                    mass = 1.0,
                    friction =1.0,
                    restitution=1.0,
                    trigger = true,
                    mask = 1,
                    group = 2
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
        name = "Ogreman4",
        components = {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {60, 0, 0},
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
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 2,
                    size = {2, 2, 2},
                    mass = 1.0,
                    friction =1.0,
                    restitution=1.0,
                    trigger = true,
                    mask = 1,
                    group = 2
                }
            },
            {
                name="NodeComponent",
                parameters={
                    ispatrol=true,
                    cost=1.8,
                    hcost=1.8,
                    iswalkable=true,
                    id=2

                }

            },
        }
    },
    
    {
        name = "Ogreman5",
        components = {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {10, 0, -30},
                    rotation = {0, 0, 0},
                    scale = {1, 1, 1}                   
                }
            },
            {
                name = "MeshRenderComponent",
                parameters = {                  
                    isstatic = false,
                    modelname = "Sinbad.mesh",
                    entityname= "sinbad5",
                    materialname = "Sinbad/Gold"
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
                    movementType = 2,
                    size = {2, 2, 2},
                    mass = 1.0,
                    friction =1.0,
                    restitution=1.0,
                    trigger = true,
                    mask = 1,
                    group = 2
                }
            },
            {
                name="NodeComponent",
                parameters={
                    ispatrol=false,
                    cost=1.8,
                    hcost=1.8,
                    iswalkable=true,
                    id=3

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
                    position = {10, 0, 70},
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
    }, 
    
    {
        name = "Ogreman",
        components = {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {-10, 0, 0},
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
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 0,
                    size = {2, 2, 2},
                    mass = 1.0,
                    friction =1.0,
                    restitution=1.0,
                    trigger = false,
                    mask = 2,
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
                name="OgremanControllerComponent",
                parameters={
                    alignmentWeight=0.1,
                    cohesionWeight=0.1,
                    separationWeight=0.1,
                    maxSpeed=6.0,
                    separationDistance=2.0,
                }
            },
            {
                name="OgremanHearingComponent",
                parameters={
                    sensitivity=8,
                    rate=3.0,
                    lowerThreshold=0.4,
                    upperThreshold=1.0
                }
            }
        }
    },
    {
        name = "Suelo",
        components = 
        {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {0, -30, 0},
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
                    friction =1.0,
                    restitution=0.0,
                    trigger = false,
                    mask = 1,
                    group = 2
                }
            },
        }
    }
    
}
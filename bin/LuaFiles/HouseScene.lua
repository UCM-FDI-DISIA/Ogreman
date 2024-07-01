Entities={
    {
        name = "NoteUI",
            components = {              
                {
                    name = "UITransformComponent",
                    parameters = {    
                        position = { -0.05, 0.1 },   
                        scale = { 0.11,0.1},   
                        hidden = false   
             
                    }
                },
                {
                    name = "UITextComponent",
                    parameters = {   
                        name = "notas",
                        font = "Ogreman",
                        caption = "prueba",
                        zOrder = 7,
                        charHeight = 0.08,
                        color = {1, 0, 0}
                    }
                },
                {
                    name = "NNotesComponent",
                    parameters = {             
                        notes = 4
                    }
                }
            }
    
        }, 
    {
        name = "Player",
        components = {
            {
                name = "TransformComponent",
                parameters = {  
                    position = {-36,0,110},
                    rotation ={0, 0, 0},
                    scale = {1, 1, 1}                   
                }
            },
           
            {
                name = "CameraComponent",
                parameters = {                  
                    name = "anim",
                    position ={0,0,30},
                    color = {1, 0, 0},
                    alfa = 0.0,
                    offset = {0, 7, 0},
                    zOrder = 3
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
                    size = {2, 7.5, 2},
                    mass = 10.0,
                    friction = 10.5,
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
                name = "AudioSourceComponent",
                parameters = {
                    name = "audioCorrer",
                    path = "sonido_correr_casa.mp3",
                    onstart = false,
                    loop = true,
                    threed = false,
                    volume = 2,
                    groupchannel = "effects"
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
            {
                name = "AudioListenerComponent",
                parameters = {

                }
            }
  
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
	        },
            {
                name = "AudioSourceComponent", 
                parameters ={
                    name = "audioFondoJuego",
                    path = "sonido_fondo_juego_recortadobn.mp3",
                    onstart = true,
                    loop = true,
                    threed = false,
                    volume = 0.05,
                    groupchannel = "music"
                }
            }     
        }
    }, 
    {  
        name = "Light2",
        components = {
	        {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {-70,-0.5, 107},
                    rotation = {0, 0, 0},
                    scale = {1, 1, 1}                   
                }
            },
            {
                name = "LightComponent",
                parameters = {
                    type = 0,
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
        name = "NotaUI1",
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
                    position = { 0.0,0.0},   
                    scale = { 1.0,1.0},   
                    hidden = true   
         
                }
            },
            {
                
                name = "UISpriteRendererComponent",
                parameters = {
                    name = "notaui1", 
                    material = "nota1", 
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
        name = "Nota1",
        components = {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {25, 4.0, 48},
                    rotation = {0, 0, 90},
                    scale = {5, 5, 5}                   
                }
            },
            {
                name = "MeshRenderComponent",
                parameters = {                  
                    isstatic = false,
                    modelname = "Cuaderno.mesh",
                    entityname= "nota1",
                    materialname = "Cuaderno_Material"
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
                    name = "nota1", 
                    material = "cartelE", 
                    zOrder = 1
                }
            },
            {
                name = "AudioSourceComponent", 
                parameters ={
                    name = "audioNota1",
                    path = "sonido_obtener_objeto.mp3",
                    onstart = false,
                    loop = false,
                    threed = true,
                    mindistance = 1.0,
                    maxdistance = 30.0,
                    volume = 1.5,
                    groupchannel = "effects"
                }
            },
            {
                name = "NoteComponent",
                parameters = {
                    text = "NotaUI1"
                }
            }
        }
    },
    {
        name = "NotaUI2",
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
                    name = "notaui2", 
                    material = "nota2", 
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
        name = "Nota2",
        components = {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {181, 4.0, 140},
                    rotation = {0, -135, 90},
                    scale = {5, 5, 5}                   
                }
            },
            {
                name = "MeshRenderComponent",
                parameters = {                  
                    isstatic = false,
                    modelname = "Cuaderno.mesh",
                    entityname= "nota2",
                    materialname = "Cuaderno_Material"
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
                    name = "nota2", 
                    material = "cartelE", 
                    zOrder = 1
                }
            },
            {
                name = "AudioSourceComponent", 
                    parameters ={
                        name = "audioNota2",
                        path = "sonido_obtener_objeto.mp3",
                        onstart = false,
                        loop = false,
                        threed = true,
                        mindistance = 1.0,
                        maxdistance = 30.0,
                        volume = 1.5,
                        groupchannel = "effects"
                    }
            },
            {
                name = "NoteComponent",
                parameters = {
                    text = "NotaUI2"
                }
            }
            
        }
    },
    {
        name = "NotaUI3",
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
                    name = "notaui3", 
                    material = "nota3", 
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
        name = "Nota3",
        components = {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {134, 4.0, -19},
                    rotation = {0, -45, 90},
                    scale = {5, 5, 5}                   
                }
            },
            {
                name = "MeshRenderComponent",
                parameters = {                  
                    isstatic = false,
                    modelname = "Cuaderno.mesh",
                    entityname= "nota3",
                    materialname = "Cuaderno_Material"
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
                    name = "nota3", 
                    material = "cartelE", 
                    zOrder = 1
                }
            },
            {
                name = "AudioSourceComponent", 
                    parameters ={
                        name = "audioNota3",
                        path = "sonido_obtener_objeto.mp3",
                        onstart = false,
                        loop = false,
                        threed = true,
                        mindistance = 1.0,
                        maxdistance = 30.0,
                        volume = 1.5,
                        groupchannel = "effects"
                    }
            },
            {
                name = "NoteComponent",
                parameters = {
                    text = "NotaUI3"
                }
            }
            
        }
    },
    {
        name = "NotaUI4",
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
                    name = "notaui4", 
                    material = "nota4", 
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
        name = "Nota4",
        components = {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {43, 4.0, 178},
                    rotation = {0, 135, 90},
                    scale = {5, 5, 5}                   
                }
            },
            {
                name = "MeshRenderComponent",
                parameters = {                  
                    isstatic = false,
                    modelname = "Cuaderno.mesh",
                    entityname= "nota4",
                    materialname = "Cuaderno_Material"
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
                    name = "nota4", 
                    material = "cartelE", 
                    zOrder = 1
                }
            },
            {
                name = "AudioSourceComponent", 
                parameters ={
                    name = "audioNota4",
                    path = "sonido_obtener_objeto.mp3",
                    onstart = false,
                    loop = false,
                    threed = true,
                    mindistance = 1.0,
                    maxdistance = 30.0,
                    volume = 1.5,
                    groupchannel = "effects"
                }
            },
            {
                name = "NoteComponent",
                parameters = {
                    text = "NotaUI4"
                }
            }
            
        }
    },
    {
        name = "PilaUI1",
            components = {
            {
                name = "TransformComponent",
                parameters = {
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
                name = "ShowImageComponent",
                parameters = {
                    ttoshow = 5.0
                }
            }
            
        }
    },
    {
        name = "Pila1",
        components = {
            {
                name = "TransformComponent",
                parameters = {  
                    position = {-36,0,70},
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
                    materialname = "Pila_BakedBatteryC"
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
                    material = "cartelE", 
                    zOrder = 1
                }
            },
            {
                name = "AudioSourceComponent", 
                    parameters ={
                        name = "audioPila1",
                        path = "sonido_obtener_objeto.mp3",
                        onstart = false,
                        loop = false,
                        threed = true,
                        mindistance = 1.0,
                        maxdistance = 45.0,
                        volume = 1.5,
                        groupchannel = "effects"
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
        name = "Screamer",
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
                name ="AudioSourceComponent",
                parameters ={
                    name = "audioScreamer",
                    path = "sonido_pillado_por_jefe.mp3",
                    onstart = false,
                    loop = false,
                    volume = 1.0,
                    groupchannel = "effects"
                }
            },
            {
                
                name = "UISpriteRendererComponent",
                parameters = {
                    name = "screamer", 
                    material = "UI/screamer", 
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
                    friction =1.0,
                    restitution=0.0,
                    trigger = false,
                    mask = 1,
                    group = 2
                }
            },
        }
    },
    {
        name = "CasaCollider1",
        components = 
        {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {-37, 0, 121},
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
                    movementType = 2,
                    size = {100, 100, 1},
                    mass = 100000.0,
                    friction =1.0,
                    restitution=0.0,
                    trigger = false,
                    mask = 1,
                    group = 2
                }
            },
        }
    },
    {
        name = "CasaCollider2",
        components = 
        {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {92, 0, 121},
                    rotation = {0, 0, 0},
                    scale = {1, 1, 1}                   
                }
            }, {
                name = "ColliderComponent",
                parameters = {
                 }
             },
            {
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 2,
                    size = {15, 100, 1},
                    mass = 100000.0,
                    friction =1.0,
                    restitution=0.0,
                    trigger = false,
                    mask = 1,
                    group = 2
                }
            },
        }
    },
    {
        name = "CasaCollider3",
        components = 
        {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {130, 0, 121},
                    rotation = {0, 0, 0},
                    scale = {1, 1, 1}                   
                }
            }, {
                name = "ColliderComponent",
                parameters = {
                 }
             },
            {
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 2,
                    size = {8, 100, 1},
                    mass = 100000.0,
                    friction =1.0,
                    restitution=0.0,
                    trigger = false,
                    mask = 1,
                    group = 2
                }
            },
        }
    },
    {
        name = "CasaCollider4",
        components = 
        {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {-98, 0, 47},
                    rotation = {0, 0, 0},
                    scale = {1, 1, 1}                   
                }
            }, {
                name = "ColliderComponent",
                parameters = {
                 }
             },
            {
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 2,
                    size = {4, 100, 1},
                    mass = 100000.0,
                    friction =1.0,
                    restitution=0.0,
                    trigger = false,
                    mask = 1,
                    group = 2
                }
            },
        }
    },
    {
        name = "CasaCollider5",
        components = 
        {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {-60, 0, -9},
                    rotation = {0, 0, 0},
                    scale = {1, 1, 1}                   
                }
            }, {
                name = "ColliderComponent",
                parameters = {
                 }
             },
            {
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 2,
                    size = {73, 100, 0.5},
                    mass = 100000.0,
                    friction =1.0,
                    restitution=0.0,
                    trigger = false,
                    mask = 1,
                    group = 2
                }
            },
        }
    },
    {
        name = "CasaCollider6",
        components = 
        {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {-5, 0, 45},
                    rotation = {0, 0, 0},
                    scale = {1, 1, 1}                   
                }
            }, {
                name = "ColliderComponent",
                parameters = {
                 }
             },
            {
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 2,
                    size = {73, 100, 0.5},
                    mass = 100000.0,
                    friction =1.0,
                    restitution=0.0,
                    trigger = false,
                    mask = 1,
                    group = 2
                }
            },
        }
    },
    {
        name = "CasaCollider7",
        components = 
        {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {80, 0, -24},
                    rotation = {0, 0, 0},
                    scale = {1, 1, 1}                   
                }
            }, {
                name = "ColliderComponent",
                parameters = {
                 }
             },
            {
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 2,
                    size = {73, 100, 0.5},
                    mass = 100000.0,
                    friction =1.0,
                    restitution=0.0,
                    trigger = false,
                    mask = 1,
                    group = 2
                }
            },
        }
    },
    {
        name = "CasaCollider8",
        components = 
        {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {100, 0, 184},
                    rotation = {0, 0, 0},
                    scale = {1, 1, 1}                   
                }
            }, {
                name = "ColliderComponent",
                parameters = {
                 }
             },
            {
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 2,
                    size = {80, 100, 1},
                    mass = 100000.0,
                    friction =1.0,
                    restitution=0.0,
                    trigger = false,
                    mask = 1,
                    group = 2
                }
            },
        }
    },
    {
        name = "CasaCollider9",
        components = 
        {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {205, 0, 97},
                    rotation = {0, 0, 0},
                    scale = {1, 1, 1}                   
                }
            }, {
                name = "ColliderComponent",
                parameters = {
                 }
             },
            {
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 2,
                    size = {80, 100, 1},
                    mass = 100000.0,
                    friction =1.0,
                    restitution=0.0,
                    trigger = false,
                    mask = 1,
                    group = 2
                }
            },
        }
    },
    {
        name = "CasaCollider10",
        components = 
        {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {27, 0, 97},
                    rotation = {0, 0, 0},
                    scale = {1, 1, 1}                   
                }
            }, {
                name = "ColliderComponent",
                parameters = {
                 }
             },
            {
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 2,
                    size = {15, 100, 1},
                    mass = 100000.0,
                    friction =1.0,
                    restitution=0.0,
                    trigger = false,
                    mask = 1,
                    group = 2
                }
            },
        }
    },
    {
        name = "CasaCollider11",
        components = 
        {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {61, 0, 97},
                    rotation = {0, 0, 0},
                    scale = {1, 1, 1}                   
                }
            }, {
                name = "ColliderComponent",
                parameters = {
                 }
             },
            {
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 2,
                    size = {3, 100, 1},
                    mass = 100000.0,
                    friction =1.0,
                    restitution=0.0,
                    trigger = false,
                    mask = 1,
                    group = 2
                }
            },
        }
    },
    {
        name = "CasaCollider12",
        components = 
        {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {100.5, 0, 97},
                    rotation = {0, 0, 0},
                    scale = {1, 1, 1}                   
                }
            }, {
                name = "ColliderComponent",
                parameters = {
                 }
             },
            {
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType =2,
                    size = {9, 100, 1},
                    mass = 100000.0,
                    friction =1.0,
                    restitution=0.0,
                    trigger = false,
                    mask = 1,
                    group = 2
                }
            },
        }
    },
    {
        name = "CasaCollider13",
        components = 
        {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {144, 0, 146},
                    rotation = {0, 0, 0},
                    scale = {1, 1, 1}                   
                }
            }, {
                name = "ColliderComponent",
                parameters = {
                 }
             },
            {
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 2,
                    size = {6, 100, 1},
                    mass = 100000.0,
                    friction =1.0,
                    restitution=0.0,
                    trigger = false,
                    mask = 1,
                    group = 2
                }
            },
        }
    },
    {
        name = "CasaCollider14",
        components = 
        {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {174, 0, 146},
                    rotation = {0, 0, 0},
                    scale = {1, 1, 1}                   
                }
            }, {
                name = "ColliderComponent",
                parameters = {
                 }
             },
            {
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 2,
                    size = {10, 100, 1},
                    mass = 100000.0,
                    friction =1.0,
                    restitution=0.0,
                    trigger = false,
                    mask = 1,
                    group = 2
                }
            },
        }
    },
    {
        name = "CasaCollider15",
        components = 
        {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {115, 0, 44},
                    rotation = {0, 0, 0},
                    scale = {1, 1, 1}                   
                }
            }, {
                name = "ColliderComponent",
                parameters = {
                 }
             },
            {
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 2,
                    size = {27, 100, 1},
                    mass = 100000.0,
                    friction =1.0,
                    restitution=0.0,
                    trigger = false,
                    mask = 1,
                    group = 2
                }
            },
        }
    },
    {
        name = "CasaCollider16",
        components = 
        {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {-102, 0, 43},
                    rotation = {0, 90, 0},
                    scale = {1, 1, 1}                   
                }
            }, {
                name = "ColliderComponent",
                parameters = {
                 }
             },
            {
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 2,
                    size = {100, 100, 1},
                    mass = 100000.0,
                    friction =1.0,
                    restitution=0.0,
                    trigger = false,
                    mask = 1,
                    group = 2
                }
            },
        }
    },
    {
        name = "CasaCollider17",
        components = 
        {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {13, 0, 0},
                    rotation = {0, 90, 0},
                    scale = {1, 1, 1}                   
                }
            }, {
                name = "ColliderComponent",
                parameters = {
                 }
             },
            {
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 2,
                    size = {23, 100, 1},
                    mass = 100000.0,
                    friction =1.0,
                    restitution=0.0,
                    trigger = false,
                    mask = 1,
                    group = 2
                }
            },
        }
    },
    {
        name = "CasaCollider18",
        components = 
        {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {13, 0, 58},
                    rotation = {0, 90, 0},
                    scale = {1, 1, 1}                   
                }
            }, {
                name = "ColliderComponent",
                parameters = {
                 }
             },
            {
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 2,
                    size = {20, 100, 1},
                    mass = 100000.0,
                    friction =1.0,
                    restitution=0.0,
                    trigger = false,
                    mask = 1,
                    group = 2
                }
            },
        }
    },
    {
        name = "CasaCollider19",
        components = 
        {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {13, 0, 97},
                    rotation = {0, 90, 0},
                    scale = {1, 1, 1}                   
                }
            }, {
                name = "ColliderComponent",
                parameters = {
                 }
             },
            {
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 2,
                    size = {4, 100, 1},
                    mass = 100000.0,
                    friction =1.0,
                    restitution=0.0,
                    trigger = false,
                    mask = 1,
                    group = 2
                }
            },
        }
    },
    {
        name = "CasaCollider20",
        components = 
        {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {13, 0, 118},
                    rotation = {0, 90, 0},
                    scale = {1, 1, 1}                   
                }
            }, {
                name = "ColliderComponent",
                parameters = {
                 }
             },
            {
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 2,
                    size = {2, 100, 1},
                    mass = 100000.0,
                    friction =1.0,
                    restitution=0.0,
                    trigger = false,
                    mask = 1,
                    group = 2
                }
            },
        }
    },
    {
        name = "CasaCollider21",
        components = 
        {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {37, 0, 47},
                    rotation = {0, 90, 0},
                    scale = {1, 1, 1}                   
                }
            }, {
                name = "ColliderComponent",
                parameters = {
                 }
             },
            {
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 2,
                    size = {50, 100, 1},
                    mass = 100000.0,
                    friction =1.0,
                    restitution=0.0,
                    trigger = false,
                    mask = 1,
                    group = 2
                }
            },
        }
    },
    {
        name = "CasaCollider22",
        components = 
        {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {63, 0, 70},
                    rotation = {0, 90, 0},
                    scale = {1, 1, 1}                   
                }
            }, {
                name = "ColliderComponent",
                parameters = {
                 }
             },
            {
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 2,
                    size = {25, 100, 1},
                    mass = 100000.0,
                    friction =1.0,
                    restitution=0.0,
                    trigger = false,
                    mask = 1,
                    group = 2
                }
            },
        }
    },
    {
        name = "CasaCollider23",
        components = 
        {
            {
                name = "TransformComponent",
                parameters = {  
                        a = 0,
                        position = {93, 0, 70},
                        rotation = {0, 90, 0},
                        scale = {1, 1, 1}                   
                }
            }, {
                name = "ColliderComponent",
                parameters = {
                 }
             },
            {
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 2,
                    size = {25, 100, 1},
                    mass = 100000.0,
                    friction =1.0,
                    restitution=0.0,
                    trigger = false,
                    mask = 1,
                    group = 2
                }
            },
        }
    },
    {
        name = "CasaCollider24",
        components = 
        {
            {
                name = "TransformComponent",
                parameters = {  
                        a = 0,
                        position = {141, 0, 60},
                        rotation = {0, 90, 0},
                        scale = {1, 1, 1}                   
                }
            }, {
                name = "ColliderComponent",
                parameters = {
                 }
             },
            {
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 2,
                    size = {87, 100, 1},
                    mass = 100000.0,
                    friction =1.0,
                    restitution=0.0,
                    trigger = false,
                    mask = 1,
                    group = 2
                }
            },
        }
    },
    {
        name = "CasaCollider25",
        components = 
        {
            {
                name = "TransformComponent",
                parameters = {  
                        a = 0,
                        position = {37, 0, -22},
                        rotation = {0, 90, 0},
                        scale = {1, 1, 1}                   
                }
            }, {
                name = "ColliderComponent",
                parameters = {
                 }
             },
            {
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 2,
                    size = {4, 100, 1},
                    mass = 100000.0,
                    friction =1.0,
                    restitution=0.0,
                    trigger = false,
                    mask = 1,
                    group = 2
                }
            },
        }
    },
    {
        name = "CasaCollider26",
        components = 
        {
            {
                name = "TransformComponent",
                parameters = {  
                        a = 0,
                        position = {37, 0, 152},
                        rotation = {0, 90, 0},
                        scale = {1, 1, 1}                   
                }
            }, {
                name = "ColliderComponent",
                parameters = {
                 }
             },
            {
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 2,
                    size = {30, 100, 1},
                    mass = 100000.0,
                    friction =1.0,
                    restitution=0.0,
                    trigger = false,
                    mask = 1,
                    group = 2
                }
            },
        }
    },
    {
        name = "CasaCollider27",
        components = 
        {
            {
                name = "TransformComponent",
                parameters = {  
                        a = 0,
                        position = {88, 0, 126},
                        rotation = {0, 90, 0},
                        scale = {1, 1, 1}                   
                }
            }, {
                name = "ColliderComponent",
                parameters = {
                 }
             },
            {
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 2,
                    size = {4, 100, 1},
                    mass = 100000.0,
                    friction =1.0,
                    restitution=0.0,
                    trigger = false,
                    mask = 1,
                    group = 2
                }
            },
        }
    },
    {
        name = "CasaCollider27",
        components = 
        {
            {
                name = "TransformComponent",
                parameters = {  
                        a = 0,
                        position = {88, 0, 166},
                        rotation = {0, 90, 0},
                        scale = {1, 1, 1}                   
                }
            }, {
                name = "ColliderComponent",
                parameters = {
                 }
             },
            {
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 2,
                    size = {21, 100, 1},
                    mass = 100000.0,
                    friction =1.0,
                    restitution=0.0,
                    trigger = false,
                    mask = 1,
                    group = 2
                }
            },
        }
    },
    {
        name = "CasaCollider28",
        components = 
        {
            {
                name = "TransformComponent",
                parameters = {  
                        a = 0,
                        position = {172, 0, 167},
                        rotation = {0, 90, 0},
                        scale = {1, 1, 1}                   
                }
            }, {
                name = "ColliderComponent",
                parameters = {
                 }
             },
            {
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 2,
                    size = {20, 100, 1},
                    mass = 100000.0,
                    friction =1.0,
                    restitution=0.0,
                    trigger = false,
                    mask = 1,
                    group = 2
                }
            },
        }
    },
    {
        name = "CasaCollider29",
        components = 
        {
            {
                name = "TransformComponent",
                parameters = {  
                        a = 0,
                        position = {188, 0, 121},
                        rotation = {0, 90, 0},
                        scale = {1, 1, 1}                   
                }
            }, {
                name = "ColliderComponent",
                parameters = {
                 }
             },
            {
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 1,
                    size = {30, 100, 1},
                    mass = 100000.0,
                    friction =1.0,
                    restitution=0.0,
                    trigger = false,
                    mask = 1,
                    group = 2
                }
            },
        }
    },
    
   
    {
        name = "Nodo0",
       components = {
           {
               name = "TransformComponent",
               parameters = {  
                   position = {-82, 0, 71},
                   rotation = {0, 0, 0},
                   scale = {1, 1, 1}                   
               }
           },
        --     {
        --     name = "MeshRenderComponent",
        --    parameters = {                  
        --        isstatic = false,
        --        modelname = "Sinbad.mesh",
        --        entityname= "sinbad",
        --         materialname = ""
        --     }
        -- },
          
            {
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 2,
                    size = {2,2,2},
                    mass = 1.0,
                    friction =1.0,
                    restitution=1.0,
                    trigger = true,
                    mask = 1,
                    group = 2
                }
            },{
                name = "ColliderComponent",
                parameters = {
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
    name = "Nodo1",
   components = {
       {
           name = "TransformComponent",
           parameters = {  
               a = 0,
               position = {-79, 0, 106},
               rotation = {0, 0, 0},
               scale = {1, 1, 1}                   
           }
       },
    --    {
    --     name = "MeshRenderComponent",
    --    parameters = {                  
    --        isstatic = false,
    --        modelname = "Sinbad.mesh",
    --        entityname= "sinbad",
    --         materialname = ""
    --     }
    -- },
        {
            name = "RigidBodyComponent",
            parameters = {
                shapeType = 1,
                movementType = 2,
                size = {2,2,2},
                mass = 1.0,
                friction =1.0,
                restitution=1.0,
                trigger = true,
                mask = 1,
                group = 2
            }
        },{
            name = "ColliderComponent",
            parameters = {
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
name = "Nodo2",
components = {
   {
       name = "TransformComponent",
       parameters = {  
           a = 0,
           position = {0, 0, 106},
           rotation = {0, 0, 0},
           scale = {1, 1, 1}                   
       }
   },
--    {
--     name = "MeshRenderComponent",
--    parameters = {                  
--        isstatic = false,
--        modelname = "Sinbad.mesh",
--        entityname= "sinbad",
--         materialname = ""
--     }
-- },
    {
        name = "RigidBodyComponent",
        parameters = {
            shapeType = 1,
            movementType = 1,
            size = {2, 2, 2},
            mass = 1.0,
            friction =1.0,
            restitution=1.0,
            trigger = true,
            mask = 1,
            group = 2
        }
    },{
        name = "ColliderComponent",
        parameters = {
         }
     },
     {
        name="NodeComponent",
        parameters={
        ispatrol=false,
            cost=1.8,
            hcost=1.8,
            iswalkable=true,
            id=2

        }
    }

}
},
{
name = "Nodo3",
components = {
   {
       name = "TransformComponent",
       parameters = {  
           a = 0,
           position = {-8, 0, 84},
           rotation = {0, 0, 0},
           scale = {1, 1, 1}                   
       }
   }, 
--    {
--     name = "MeshRenderComponent",
--    parameters = {                  
--        isstatic = false,
--        modelname = "Sinbad.mesh",
--        entityname= "sinbad",
--         materialname = ""
--     }
-- },
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
    },{
        name = "ColliderComponent",
        parameters = {
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
    }

}
},
{
name = "Nodo4",
components = {
   {
       name = "TransformComponent",
       parameters = {  
           a = 0,
           position = {25, 0, 84},
           rotation = {0, 0, 0},
           scale = {1, 1, 1}                   
       }
   }, 
--    {
--     name = "MeshRenderComponent",
--    parameters = {                  
--        isstatic = false,
--        modelname = "Sinbad.mesh",
--        entityname= "sinbad",
--         materialname = ""
--     }
-- },
  
    {
        name = "RigidBodyComponent",
        parameters = {
            shapeType = 1,
            movementType = 2,
            size = {2,2,2},
            mass = 1.0,
            friction =1.0,
            restitution=1.0,
            trigger = true,
            mask = 1,
            group = 2
        }
    },{
        name = "ColliderComponent",
        parameters = {
         }
     },
     {
        name="NodeComponent",
        parameters={
        ispatrol=false,
            cost=1.8,
            hcost=1.8,
            iswalkable=true,
            id=4

        }
    }

}
},


{
    name = "Nodo5",
     components = {
       {
           name = "TransformComponent",
            parameters = {  
               a = 0,
               position = {41, 0,106},
               rotation = {0, 0, 0},           
                    scale = {1, 1, 1}                   
            }   
             }, 
            --  {
            --     name = "MeshRenderComponent",
            --    parameters = {                  
            --        isstatic = false,
            --        modelname = "Sinbad.mesh",
            --        entityname= "sinbad",
            --         materialname = ""
            --     }
            -- },
      
         {
             name = "RigidBodyComponent",
             parameters = {
                shapeType = 1,
                 movementType = 1,
                 size = {2, 2, 2},
                 mass = 1.0,
                 friction =1.0,
                 restitution=1.0,
                 trigger = true,
                 mask = 1,
                 group = 2
             }
         },{
            name = "ColliderComponent",
            parameters = {
             }
         },
          {
             name="NodeComponent",
             parameters={
             ispatrol=false,
                 cost=1.8,
                 hcost=1.8,
                 iswalkable=true,
                 id=5
    
             }
         }
    
     }
     },

    {
        name = "Nodo6",
       components = {
           {
               name = "TransformComponent",
               parameters = {  
                   a = 0,
                   position = {68, 0,106},
                   rotation = {0, 0, 0},
                   scale = {1, 1, 1}                   
               }
           },
        --    {
        --     name = "MeshRenderComponent",
        --    parameters = {                  
        --        isstatic = false,
        --        modelname = "Sinbad.mesh",
        --        entityname= "sinbad",
        --         materialname = ""
        --     }
        -- },
  
          
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
            },{
                name = "ColliderComponent",
                parameters = {
                 }
             },
             {
                name="NodeComponent",
                parameters={
                ispatrol=false,
                    cost=1.8,
                    hcost=1.8,
                    iswalkable=true,
                    id=6
    
                }
            }
    
       }
    },
    {
        name = "Nodo7",
       components = {
           {
               name = "TransformComponent",
               parameters = {  
                   a = 0,
                   position = {68, 0, 140},
                   rotation = {0, 0, 0},
                   scale = {1, 1, 1}                   
               }
           }, 
        --    {
        --     name = "MeshRenderComponent",
        --    parameters = {                  
        --        isstatic = false,
        --        modelname = "Sinbad.mesh",
        --        entityname= "sinbad",
        --         materialname = ""
        --     }
        -- },
  
          
            {
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 2,
                    size = {1, 1, 1},
                    mass = 1.0,
                    friction =1.0,
                    restitution=1.0,
                    trigger = true,
                    mask = 1,
                    group = 2
                }
            },{
                name = "ColliderComponent",
                parameters = {
                 }
             },
             {
                name="NodeComponent",
                parameters={
                ispatrol=false,
                    cost=1.8,
                    hcost=1.8,
                    iswalkable=true,
                    id=7
    
                }
            }
    
       }
    },
    {
    name = "Nodo8",
    components = {
       {
           name = "TransformComponent",
           parameters = {  
               a = 0,
               position = {117, 0, 106},
               rotation = {0, 0, 0},
               scale = {1, 1, 1}                   
           }
       }, 
    --    {
    --     name = "MeshRenderComponent",
    --    parameters = {                  
    --        isstatic = false,
    --        modelname = "Sinbad.mesh",
    --        entityname= "sinbad",
    --         materialname = ""
    --     },
    -- },
       
       {
        name = "RigidBodyComponent",
        parameters = {
            shapeType = 1,
            movementType = 2,
            size = {1, 1, 1},
            mass = 1.0,
            friction =1.0,
            restitution=1.0,
            trigger = true,
            mask = 1,
            group = 2
        }
        },
    
    
    {
            name = "ColliderComponent",
            parameters = {
             }
         },
         {
            name="NodeComponent",
            parameters={
            ispatrol=false,
                cost=1.8,
                hcost=1.8,
                iswalkable=true,
                id=8
    
            }
        }
    
    }
}
,
{
    name = "Nodo9",
    components = {
       {
           name = "TransformComponent",
           parameters = {  
               a = 0,
               position = {120, 0, 141},
               rotation = {0, 0, 0},
               scale = {1, 1, 1}                   
           }
       }, 
    --    {
    --     name = "MeshRenderComponent",
    --    parameters = {                  
    --        isstatic = false,
    --        modelname = "Sinbad.mesh",
    --        entityname= "sinbad",
    --         materialname = ""
    --     },
    -- },
       
       {
        name = "RigidBodyComponent",
        parameters = {
            shapeType = 1,
            movementType = 2,
            size = {1, 1, 1},
            mass = 1.0,
            friction =1.0,
            restitution=1.0,
            trigger = true,
            mask = 1,
            group = 2
        }
        },
    
    
    {
            name = "ColliderComponent",
            parameters = {
             }
         },
         {
            name="NodeComponent",
            parameters={
            ispatrol=false,
                cost=1.8,
                hcost=1.8,
                iswalkable=true,
                id=9
    
            }
        }
    
    }
}
,
        {
            name = "Nodo10",
           components = {
               {
                   name = "TransformComponent",
                   parameters = {  
                       a = 0,
                       position = {84, 0, -12},
                       rotation = {0, 0, 0},
                       scale = {1, 1, 1}                   
                   }
               },
              
            --    {
            --     name = "MeshRenderComponent",
            --    parameters = {                  
            --        isstatic = false,
            --        modelname = "Sinbad.mesh",
            --        entityname= "sinbad",
            --         materialname = ""
            --     },
            -- },
               
               {
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 2,
                    size = {1, 1, 1},
                    mass = 1.0,
                    friction =1.0,
                    restitution=1.0,
                    trigger = true,
                    mask = 1,
                    group = 2
                }
                },
            
            
            {
                    name = "ColliderComponent",
                    parameters = {
                     }
                 },
                 {
                    name="NodeComponent",
                    parameters={
                    ispatrol=false,
                        cost=1.8,
                        hcost=1.8,
                        iswalkable=true,
                        id=10
            
                    }
                }
            
            }
        },
        {
            name = "Nodo11",
           components = {
               {
                   name = "TransformComponent",
                   parameters = {  
                       a = 0,
                       position = {-28,0,32},
                       rotation = {0, 0, 0},
                       scale = {1, 1, 1}                   
                   }
               },
              
            --    {
            --     name = "MeshRenderComponent",
            --    parameters = {                  
            --        isstatic = false,
            --        modelname = "Sinbad.mesh",
            --        entityname= "sinbad",
            --         materialname = ""
            --     },
            -- },
               
               {
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 2,
                    size = {1, 1, 1},
                    mass = 1.0,
                    friction =1.0,
                    restitution=1.0,
                    trigger = true,
                    mask = 1,
                    group = 2
                }
                },
            
            
            {
                    name = "ColliderComponent",
                    parameters = {
                     }
                 },
                 {
                    name="NodeComponent",
                    parameters={
                    ispatrol=false,
                        cost=1.8,
                        hcost=1.8,
                        iswalkable=true,
                        id=11
            
                    }
                }
            
            }
        },
        {
            name = "Nodo12",
           components = {
               {
                   name = "TransformComponent",
                   parameters = {  
                       a = 0,
                       position = {30,0,30},
                       rotation = {0, 0, 0},
                       scale = {1, 1, 1}                   
                   }
               },
              
            --    {
            --     name = "MeshRenderComponent",
            --    parameters = {                  
            --        isstatic = false,
            --        modelname = "Sinbad.mesh",
            --        entityname= "sinbad",
            --         materialname = ""
            --     },
            -- },
               
               {
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 2,
                    size = {1, 1, 1},
                    mass = 1.0,
                    friction =1.0,
                    restitution=1.0,
                    trigger = true,
                    mask = 1,
                    group = 2
                }
                },
            
            
            {
                    name = "ColliderComponent",
                    parameters = {
                     }
                 },
                 {
                    name="NodeComponent",
                    parameters={
                    ispatrol=false,
                        cost=1.8,
                        hcost=1.8,
                        iswalkable=true,
                        id=12
            
                    }
                }
            
            }
        },
        {
            name = "Nodo13",
           components = {
               {
                   name = "TransformComponent",
                   parameters = {  
                       a = 0,
                       position = {21,0,-10},
                       rotation = {0, 0, 0},
                       scale = {1, 1, 1}                   
                   }
               },
              
            --    {
            --     name = "MeshRenderComponent",
            --    parameters = {                  
            --        isstatic = false,
            --        modelname = "Sinbad.mesh",
            --        entityname= "sinbad",
            --         materialname = ""
            --     },
            -- },
               
               {
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 2,
                    size = {1, 1, 1},
                    mass = 1.0,
                    friction =1.0,
                    restitution=1.0,
                    trigger = true,
                    mask = 1,
                    group = 2
                }
                },
            
            
            {
                    name = "ColliderComponent",
                    parameters = {
                     }
                 },
                 {
                    name="NodeComponent",
                    parameters={
                    ispatrol=false,
                        cost=1.8,
                        hcost=1.8,
                        iswalkable=true,
                        id=13
            
                    }
                }
            
            }
        },  
        {
            name = "Nodo14",
           components = {
               {
                   name = "TransformComponent",
                   parameters = {  
                       a = 0,
                       position = {-88,0,26},
                       rotation = {0, 0, 0},
                       scale = {1, 1, 1}                   
                   }
               },
              
            --    {
            --     name = "MeshRenderComponent",
            --    parameters = {                  
            --        isstatic = false,
            --        modelname = "Sinbad.mesh",
            --        entityname= "sinbad",
            --         materialname = ""
            --     },
            -- },
               
               {
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 2,
                    size = {1, 1, 1},
                    mass = 1.0,
                    friction =1.0,
                    restitution=1.0,
                    trigger = true,
                    mask = 1,
                    group = 2
                }
                },
            
            
            {
                    name = "ColliderComponent",
                    parameters = {
                     }
                 },
                 {
                    name="NodeComponent",
                    parameters={
                    ispatrol=false,
                        cost=1.8,
                        hcost=1.8,
                        iswalkable=true,
                        id=14
            
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
                    rotation = {180, 0, 0},
                    scale = {8, 8, 8}                   
                }
            },
        
            {
                name="GridComponent",
                parameters={
                }
            },
            {
                name = "MeshRenderComponent",
                parameters = {                  
                    isstatic = false,
                    modelname = "Casa.mesh",
                    entityname= "npc3",
                    materialname = ""
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
                    position = {-28,0,32},
                    rotation = {0, 0, 0},
                    scale = {1, 1, 1}                   
               }
            },
            {
                name = "MeshRenderComponent",
                parameters = {                  
                    modelname = "Sinbad.mesh",
                    entityname= "Sinbad1",
                    materialname = "",
                    isstatic = false
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
                    max_dist_follow=100.0,
                    min_dist_follow=50.0
                }
            },
            {
                name = "AudioSourceComponent", 
                parameters ={
                    name = "audioOgro",
                    path = "sonido_jefe_merodeando2.mp3",
                    onstart = true,
                    loop = true,
                    threed = true,
                    mindistance = 1.0,
                    maxdistance = 60.0,
                    volume = 1.5,
                    groupchannel = "effects"
                }
            },
            {
                name = "OgremanAttackComponent",
                parameters ={
                    
                }
            },
            {
                name = "SmokeComponent",
                parameters = {
                }
            }
            
        }
    },
    {
        name = "FlashLightAudio",
        components ={
            {
                name = "TransformComponent",
                parameters = {  
                 a = 0,
                     position = {0,0,0},
                     rotation = {0, 0, 0},
                     scale = {0, 0, 0}                   
               }
            },
            {
                name = "AudioSourceComponent", 
                parameters ={
                name = "audioFlashlight1",
                path = "sonido_linterna.mp3",
                onstart = false,
                loop = false,
                threed = false,
                volume = 1.5,
                groupchannel = "effects"
                }
            }
        }
    }   
}
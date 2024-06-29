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
                    name = "notas2",
                    font = "Ogreman",
                    caption = "prueba",
                    zOrder = 17,
                    charHeight = 0.08,
                    color = {1, 0, 0}
                }
            },
            {
                name = "NNotesComponent",
                parameters = {             
                    notes = 3
                }
            }
        }
    }, {  
        name = "Light",
        components = {
	        {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {186,5,-148},
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
        name = "Player",
        components = {
            {
                name = "TransformComponent",
                parameters = {  
                    position = {186,5,-148},
                    rotation ={0, 0, 0},
                    scale = {1, 1, 1}                   
                }
            },        
            {
                name = "CameraComponent",
                parameters = {                  
                    name = "anim56785t8",
                    position ={0,0,30},
                    color = {1, 0, 0},
                    alfa = 0.0,
                    offset = {0, 7, 0},
                    zOrder = 4
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
                    progressBarName = "p2",
                    frameMaterial = "FlashLigt",
                    contentMaterial = "FlashLigtContent",
                    zOrder = 1                   
                }
            },
            {
                name = "AudioSourceComponent",
                parameters = {
                    name = "audioCorrerFueraa",
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
                name = "AudioListenerComponent",
                parameters ={

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
            }
        }
    }, 
    {  
        name = "Light",
        components = {
	        {
                name = "TransformComponent",
                parameters = {                    
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
        name = "NotaUI5",
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
                    name = "notaui5", 
                    material = "nota5", 
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
        name = "Nota5",
        components = {
            {
                name = "TransformComponent",
                parameters = {                     
                    position = {170, 0, 67},
                    rotation = {0, 0, 180},
                    scale = {5, 5, 5}                   
                }
            },
            {
                name = "MeshRenderComponent",
                parameters = {                  
                    isstatic = false,
                    modelname = "Cuaderno.mesh",
                    entityname= "nota5",
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
                    name = "nota5", 
                    material = "cartelE", 
                    zOrder = 1
                }
            },
            {
                name = "AudioSourceComponent", 
                parameters ={
                    name = "audioNota5",
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
                    text = "NotaUI5"
                }
            }
        }
    },
    {
        name = "NotaUI6",
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
                    name = "notaui6", 
                    material = "nota6", 
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
        name = "Nota6",
        components = {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {-30,0,-20},
                    rotation = {0, 0, 180},
                    scale = {5, 5, 5}                   
                }
            },
            {
                name = "MeshRenderComponent",
                parameters = {                  
                    isstatic = false,
                    modelname = "Cuaderno.mesh",
                    entityname= "nota6",
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
                    name = "nota6", 
                    material = "cartelE", 
                    zOrder = 1
                }
            },
            {
                name = "AudioSourceComponent", 
                parameters ={
                    name = "audioNota6",
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
                    text = "NotaUI6"
                }
            }
        
        }
    },
    {
        name = "NotaUI7",
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
                    name = "notaui7", 
                    material = "nota7", 
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
        name = "Nota7",
        components = {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {15,0,164},
                    rotation = {0, 0, 180},
                    scale = {5, 5, 5}                   
                }
            },
            {
                name = "MeshRenderComponent",
                parameters = {                  
                    isstatic = false,
                    modelname = "Cuaderno.mesh",
                    entityname= "nota7",
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
                    name = "nota7", 
                    material = "cartelE", 
                    zOrder = 1
                }
            },
            {
                name = "AudioSourceComponent", 
                parameters ={
                    name = "audioNota7",
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
                    text = "NotaUI7"
                }
            }
        
        }
    },
    
    {
     name = "PilaUI2",
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
        name = "Pila2",
        components = {
            {
                name = "TransformComponent",
                parameters = {  
                    position = {62,5,0},
                    rotation = {0, 0, 180},
                    scale = {5, 5, 5}                   
                }
            },
            {
                name = "MeshRenderComponent",
                parameters = {                  
                    isstatic = false,
                    modelname = "Pila.mesh",
                    entityname= "pilajardin",
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
                    name = "nombreeDDD", 
                    material = "cartelE", 
                    zOrder = 1
                }
            },
            {
                name = "AudioSourceComponent", 
                parameters ={
                    name = "audioPila2",
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
        name = "Nodo0",
        components = {
                {
                    name = "TransformComponent",
                    parameters = {  
                        a = 0,
                        position = {-105,0,-119},
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
                    position = {220,0,-148},
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
                    position = {220,0,300},
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
                name="NodeComponent",
                parameters={
                ispatrol=true,
                    cost=1.8,
                    hcost=1.8,
                    iswalkable=true,
                    id=2

                }
            }

        }
    },  {
        name = "Nodo3",
        components = {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {-105,0,300},
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
                name="NodeComponent",
                parameters={
                ispatrol=true,
                    cost=1.8,
                    hcost=1.8,
                    iswalkable=true,
                    id=3

                }
            }

        }
    }, 
    {
        name = "Jardin",
        components = {
            {
                name = "TransformComponent",
                parameters = {                 
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
                    modelname = "Arboles_jardin.mesh",
                    entityname= "npc1",
                    materialname = ""
                }
            }
        }
    }, 
    {
        name = "Jardin2",
        components = {
            {
                name = "TransformComponent",
                parameters = {                 
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
                    modelname = "Jardin_sin_arboles.mesh",
                    entityname= "npc1",
                    materialname = ""
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
                        name = "audioScreamer2",
                        path = "sonido_pillado_por_jefe.mp3",
                        onstart = false,
                        loop = false,
                        volume = 0.3,
                        groupchannel = "effects"
                    }
                },
                {
                    
                    name = "UISpriteRendererComponent",
                    parameters = {
                        name = "screamer2", 
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
        name = "Ogreman",
        components = {
            {
                name = "TransformComponent",
                parameters = {  
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
                    maxSpeed=16.0,
                    separationDistance=2.0,
                    max_dist_follow=100.0,
                    min_dist_follow=50.0
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
            },
            {
                name = "AudioSourceComponent", 
                parameters ={
                    name = "audioOgro2",
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
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 1,
                    size = {500, 20, 500},
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
        name = "NPC1",
        components = {
            {
                name = "TransformComponent",
                parameters = {  
                    position = {186,1,-148},
                    rotation ={0, 0, 0},
                    scale = {100, 100, 100}                   
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
                name = "MeshRenderComponent",
                parameters = {                  
                    isstatic = false,
                    modelname = "lagartija.mesh",
                    entityname= "NPC1",
                    materialname = "lagartijaMaterial"
                    }
            },
            {
                name= "MerodeoMovementComponent",
                parameters={

                    }
            },
            {
                name = "AudioSourceComponent",
                parameters = {
                    name = "audioLagartija",
                    path = "sonido_lagartija_idle.mp3",
                    onstart = true,
                    loop = true,
                    threed = false,
                    volume = 2,
                    groupchannel = "effects"
                }
            }
        }
    },
    {
        name = "Pared1",
        components = 
        {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {-137, -28, -254},
                    rotation = {0, 0, 0},
                    scale = {1, 1, 1}                   
                }
            },
            {
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 1,
                    size = {500, 500, 100},
                    mass = 100000.0,
                    friction =1.0,
                    restitution=0.0,
                    trigger = false,
                    mask = 1,
                    group = 2
                }
            },
        }
    },{
        name = "Pared2",
        components = 
        {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {272, -28, -50},
                    rotation = {0, 0, 0},
                    scale = {1, 1, 1}                   
                }
            },
            {
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 1,
                    size = {100, 500, 500},
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
        name = "Pared3",
        components = 
        {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {-195, -28, -100},
                    rotation = {0, 0, 0},
                    scale = {1, 1, 1}                   
                }
            },
            {
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 1,
                    size = {20, 500, 500},
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
        name = "Pared4",
        components = 
        {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {-195, -28, -100},
                    rotation = {0, 0, 0},
                    scale = {1, 1, 1}                   
                }
            },
            {
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 1,
                    size = {20, 500, 500},
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
                    entityname= "lagartija",
                    materialname = "lagartijaMaterial"
                    }
            },
            {
                name= "MerodeoMovementComponent",
                parameters={

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
                        name = "audioFlashlight2",
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

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
                    position = {20, 6, 50},
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
                    zOrder = 20
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
                    a = 0,
                    position = {-70.25, 5.0, 107.44},
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
                    name = "nota5", 
                    material = "cartelE", 
                    zOrder = 1
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
                position = {11.87, 5.0, 35.168},
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
                name = "nota6", 
                material = "cartelE", 
                zOrder = 1
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
                position = {126, 5.0, 2.09},
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
                name = "nota7", 
                material = "cartelE", 
                zOrder = 1
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
    name = "Nodo0",
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
                position = {-35, 0, 0},
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
               position = {-65, 0, 0},
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
               position = {-90, 0, 0},
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
               position = {0, 0, 30},
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
               position = {-35, 0, 35},
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
           position = {-65, 0, 35},
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
           position = {-90, 0, 35},
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
               position = {-90, 0, 50},
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
            ispatrol=false,
                cost=1.8,
                hcost=1.8,
                iswalkable=true,
                id=8
    
            }
        }
    
    }
    },
    {
        name = "Nodo9",
        components = {
           {
               name = "TransformComponent",
               parameters = {  
                   a = 0,
                   position = {-90, 0, 110},
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
                ispatrol=false,
                    cost=1.8,
                    hcost=1.8,
                    iswalkable=true,
                    id=9
        
                }
            }
        
        }
        },

        {
            name = "Nodo10",
           components = {
               {
                   name = "TransformComponent",
                   parameters = {  
                       a = 0,
                       position = {0, 0, 110},
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
                       position = {-35, 0, 110},
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
                   position = {-65, 0, 110},
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
                       position = {-90, 0, 80},
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
                           position = {0, 0, 80},
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
                name = "Nodo15",
               components = {
                   {
                       name = "TransformComponent",
                       parameters = {  
                           a = 0,
                           position = {-35, 0, 80},
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
                        ispatrol=false,
                            cost=1.8,
                            hcost=1.8,
                            iswalkable=true,
                            id=15
            
                        }
                    }
            
               }
            },
            {
            name = "Nodo16",
            components = {
               {
                   name = "TransformComponent",
                   parameters = {  
                       a = 0,
                       position = {-65, 0, 80},
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
                    ispatrol=false,
                        cost=1.8,
                        hcost=1.8,
                        iswalkable=true,
                        id=16
            
                    }
                }
            
            }
            },
            {
                name = "Nodo17",
               components = {
                   {
                       name = "TransformComponent",
                       parameters = {  
                           a = 0,
                           position = {20, 0, 110},
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
                        ispatrol=false,
                            cost=1.8,
                            hcost=1.8,
                            iswalkable=true,
                            id=17
            
                        }
                    }
            
               }
            },
            {
                name = "Nodo18",
               components = {
                   {
                       name = "TransformComponent",
                       parameters = {  
                           a = 0,
                           position = {50, 0, 110},
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
                        ispatrol=false,
                            cost=1.8,
                            hcost=1.8,
                            iswalkable=true,
                            id=18
            
                        }
                    }
            
               }
            },
            {
            name = "Nodo19",
            components = {
               {
                   name = "TransformComponent",
                   parameters = {  
                       a = 0,
                       position = {70, 0, 110},
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
                    ispatrol=false,
                        cost=1.8,
                        hcost=1.8,
                        iswalkable=true,
                        id=19   
            
                    }
                }
            
            }
            },
            
            {
            name = "Nodo20",
            components = {
               {
                   name = "TransformComponent",
                   parameters = {  
                       a = 0,
                       position = {113, 0, 110},
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
                    ispatrol=false,
                        cost=1.8,
                        hcost=1.8,
                        iswalkable=true,
                        id=20
            
                    }
                }
            
            }
            },
            {
                name = "Nodo21",
                components = {
                   {
                       name = "TransformComponent",
                       parameters = {  
                           a = 0,
                           position = {112, 0, 140},
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
                        ispatrol=false,
                            cost=1.8,
                            hcost=1.8,
                            iswalkable=true,
                            id=21
                
                        }
                    }
                
                }
                },
                {
                    name = "Nodo22",
                    components = {
                       {
                           name = "TransformComponent",
                           parameters = {  
                               a = 0,
                               position = {112, 0, 170},
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
                            ispatrol=false,
                                cost=1.8,
                                hcost=1.8,
                                iswalkable=true,
                                id=22
                    
                            }
                        }
                    
                    }
                    },
                    {
                        name = "Nodo23",
                        components = {
                           {
                               name = "TransformComponent",
                               parameters = {  
                                   a = 0,
                                   position = {130, 0, 170},
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
                                ispatrol=false,
                                    cost=1.8,
                                    hcost=1.8,
                                    iswalkable=true,
                                    id=23
                        
                                }
                            }
                        
                        }
                        },

                        {
                            name = "Nodo24",
                            components = {
                               {
                                   name = "TransformComponent",
                                   parameters = {  
                                       a = 0,
                                       position = {155, 0, 170},
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
                                    ispatrol=false,
                                        cost=1.8,
                                        hcost=1.8,
                                        iswalkable=true,
                                        id=24
                            
                                    }
                                }
                            
                            }
                },
 
                {
                    name = "Nodo25",
                    components = {
                       {
                           name = "TransformComponent",
                           parameters = {  
                               a = 0,
                               position = {70, 0, 138},
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
                            ispatrol=false,
                                cost=1.8,
                                hcost=1.8,
                                iswalkable=true,
                                id=25
                    
                            }
                        }
                    
                    }
        },
        {
            name = "Nodo26",
            components = {
               {
                   name = "TransformComponent",
                   parameters = {  
                       a = 0,
                       position = {70, 0, 170},
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
                    ispatrol=false,
                        cost=1.8,
                        hcost=1.8,
                        iswalkable=true,
                        id=26
            
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
                    entityname= "npc1",
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
                     maxSpeed=6.0,
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
    -- {
    --     name = "NPC1",
    --     components = {
    --         {
    --             name = "TransformComponent",
    --             parameters = {  
    --                 position = {20, 0, 0},
    --                 rotation ={0, 0, 0},
    --                 scale = {10, 10, 10}                   
    --             }
    --         },
           
           
    --         {
    --             name = "LightComponent",
    --             parameters = {
    --                 type = 1,
    --                 diffusecolour = {1, 1, 1},
    --                 shadowfardist = 25.0,
    --                 shadowdist = 25.0,
    --                 ineerangle = 90.0,
    --                 outerangle = 180.0,
    --                 nearclipdist = 0.1,
    --                 shdws = true
    --             }
	--         },
    --         {
    --             name = "ColliderComponent",
    --             parameters = {
    --             }
    --         },
    --         {
    --             name = "RigidBodyComponent",
    --             parameters = {
    --                 shapeType = 1,
    --                 movementType = 0,
    --                 size = {2, 6, 2},
    --                 mass = 10.0,
    --                 friction = 0.5,
    --                 restitution = 0.0,
    --                 trigger = false,
    --                 mask = 2,
    --                 group = 1
    --             }
    --         },
    --         {
    --             name = "MovementComponent",
    --             parameters = {                  
                    
    --             }
    --         },     
    --         {
    --             name = "MeshRenderComponent",
    --             parameters = {                  
    --                 isstatic = false,
    --                 modelname = "lagartija.mesh",
    --                 entityname= "npc1",
    --                 materialname = "Sinbad/Gold"
    --                 }
    --         },
    --         {
    --             name= "MerodeoMovementComponent",
    --             parameters={

    --                 }
    --         }
    --     }
    -- }
    
}
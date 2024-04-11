Entities={
    {
        name = "Player",
        components = {
            {
                name = "TransformComponent",
                parameters = {  
                    position = {0, 0, 20},
                    rotation ={0, 0, 0},
                    scale = {1, 1, 1}                   
                }
            },
            {
                name = "MeshRenderComponent",
                parameters = {                  
                    isstatic = true,
                    modelname = "Sinbad.mesh",
                    entityname= "sinbad",
                    materialname = ""
                }
            },
            {
                name = "AudioSourceComponent",
                parameters = {                  
                    name = "sonido",
                    path = "sonido_jefe_merodeando2.mp3",
                    groupchannel = "sonido",
                    onstart = true,
                    loop = true,
                    threed = true,
                    volume = 1000,
                    mindistance = 0,
                    maxdistance = 100000
                }
            },
            {
                name = "AudioListenerComponent",
                parameters = {                  
                   
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
                    color = {0.8, 0.3, 1},
                    offset = {100, 100, 100}
                }
            },
            {
                name = "InputComponent",
                parameters = {                  
                    
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
                    position = {0, 0, 20},
                    rotation = {0, 0, 0},
                    scale = {1, 1, 1}                   
                }
            },
            {
                name = "Light",
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
                    position = {0, 0, 20},
                    rotation = {0, 0, 0},
                    scale = {1, 1, 1}                   
                }
            },
            {
                name = "MeshRenderComponent",
                parameters = {                  
                    isstatic = true,
                    modelname = "Sinbad.mesh",
                    entityname= "sinbad",
                    materialname = ""
                }
            }     
        }
    },
    {
        name = "nodo1",
        components = {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {0, 10, 205},
                    rotation = {0, 10, 25},
                    scale = {1, 1, 1}                   
                }
            },
            {
                name = "MeshRenderComponent",
                parameters = {                  
                    isstatic = true,
                    modelname = "Sinbad.mesh",
                    entityname= "sinbad",
                    materialname = ""
                }
            },
            {
                name = "NodeComponent",
                parameters = {                  
                    id = 1,
                    ispatrol = true,
                    iswalkable = true,
                    hcost = 10,
                    cost = 1000
                }
            }          
        }
    }
}
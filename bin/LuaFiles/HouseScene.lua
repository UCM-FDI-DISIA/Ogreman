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
    }
    
}
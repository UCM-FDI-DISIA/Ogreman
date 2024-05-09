Entities={
    {
        name = "ExitButton",
        components = {           
            {
                name = "UITransformComponent",
                parameters = {                  
                    position = {0.4, 0.7},
                    scale = {0.2, 0.1},
                    hidden = false     
                }
            },
            {        
                name = "UISpriteRendererComponent",
                parameters = {
                    name = "exit2", 
                    material = "exitbutton", 
                    zOrder = 1
                }
            },
            {
                name = "ExitButtonComponent",
                parameters = {  
                                  
                }
            }
        }
    },
    {
        name = "Gameover",
        components = {           
            {
                name = "UITransformComponent",
                parameters = {                  
                    position = {0.2, 0.05},
                    scale = {0.6, 0.25},
                    hidden = false     
                }
            },
            {        
                name = "UISpriteRendererComponent",
                parameters = {
                    name = "gameover", 
                    material = "gameover", 
                    zOrder = 1
                }
            }
        }
    },
    {
        name = "Camera",
        components = {
            {
                name = "TransformComponent",
                parameters = {               
                    position = {0.0, 0.0, 0.0},
                    rotation = {0.0, 0.0, 0.0},
                    scale = {1, 1, 1}                   
                }
            },
            {
                name = "CameraComponent",
                parameters = {
                    name = "lose",
                    color = {0.0, 0.0, 0.0},
                    offset = {0.0, 0.0, 0.0},
                    zOrder = 5
                }
            }
        }
    }
}
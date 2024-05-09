Entities={
    {
        name = "MenuButton",
        components = {           
            {
                name = "UITransformComponent",
                parameters = {                  
                    position = {0.4, 0.5},
                    scale = {0.2, 0.1},
                    hidden = false     
                }
            },
            {        
                name = "UISpriteRendererComponent",
                parameters = {
                    name = "menu", 
                    material = "menu", 
                    zOrder = 1
                }
            },
            {
                name = "MenuButtonComponent",
                parameters = {  
                                  
                }
            }
        }
    },
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
        name = "Escaped",
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
                    name = "escaped", 
                    material = "escaped", 
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
                    name = "win",
                    color = {0.0, 0.0, 0.0},
                    offset = {0.0, 0.0, 0.0},
                    zOrder = 5
                }
            }
        }
    }
}
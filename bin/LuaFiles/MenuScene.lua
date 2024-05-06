Entities={
    {
        name = "ControlsButton",
        components = {           
            {
                name = "UITransformComponent",
                parameters = {                  
                    position = {0.4, 0.3},
                    scale = {0.2, 0.1},
                    hidden = false     
                }
            },
            {
                name = "UITextComponent",
                parameters = {                  
                    name = "controlsbutton",
                    font = "Ogreman",
                    caption = "PLAY",
                    zOrder = 3,
                    charHeight = 0.1,
                    color = {1.0,1.0,1.0} 
                }
            },
            {
                name = "ControlsButtonComponent",
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
                    position = {0.4, 0.6},
                    scale = {0.2, 0.1},
                    hidden = false     
                }
            },
            {
                name = "UITextComponent",
                parameters = {                  
                    name = "exitbutton",
                    font = "Ogreman",
                    caption = "EXIT",
                    zOrder = 3,
                    charHeight = 0.1,
                    color = {1.0,1.0,1.0} 
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
        name = "Background",
        components = {           
            {
                name = "UITransformComponent",
                parameters = {                  
                    position = {0.0, 0.0},
                    scale = {1.0, 1.0},
                    hidden = false     
                }
            },
            {
                name = "UISpriteRendererComponent",
                parameters = {                  
                    name = "background", 
                    material = "UI/fondoMenu", 
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
                    a = 0,
                    position = {0.0, 0.0, 0.0},
                    rotation = {0.0, 0.0, 0.0},
                    scale = {1, 1, 1}                   
                }
            },
            {
                name = "CameraComponent",
                parameters = {
                    name = "menu",
                    color = {0.0, 0.0, 0.0},
                    offset = {0.0, 0.0, 0.0}, 
                    zOrder = 0
                }
            }
        }
    }
}
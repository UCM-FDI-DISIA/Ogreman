Entities={
    {
        name = "MenuButton",
        components = {           
            {
                name = "UITransformComponent",
                parameters = {                  
                    position = {0.5, 0.4},
                    scale = {0.1, 0.1},
                    hidden = false     
                }
            },
            {
                name = "UITextComponent",
                parameters = {                  
                    name = "menubuttonlose",
                    font = "Ogreman",
                    caption = "MENU",
                    zOrder = 3,
                    charHeight = 0.1,
                    color = {1.0,1.0,1.0} 
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
                    position = {0.5, 0.6},
                    scale = {0.1, 0.1},
                    hidden = false     
                }
            },
            {
                name = "UITextComponent",
                parameters = {                  
                    name = "exitbuttonlose",
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
                    name = "lose",
                    color = {0.0, 0.0, 0.0},
                    offset = {0.0, 0.0, 0.0}
                }
            }
        }
    }
}
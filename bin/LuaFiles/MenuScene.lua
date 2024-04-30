Entities={
    {
        name = "PlayButton",
        components = {           
            {
                name = "UITransformComponent",
                parameters = {                  
                    position = {0, 0},
                    scale = {100, 100},
                    hidden = false     
                }
            },
            {
                name = "UITextComponent",
                parameters = {                  
                    name = "test",
                    font = "Ogreman",
                    caption = "Entro a HouseScene",
                    zOrder = 3,
                    charHeight = 0.1,
                    color = {1,0,0} 
                }
            },
            {
                name = "UIButtonComponent",
                parameters = {  
                                  
                }
            },
            {
                name = "PlayButtonComponent",
                parameters = {  
                                  
                }
            }
        }
    },
    {
        name = "Camera",
        components = {
            {
                name = "CameraComponent",
                parameters = {
                    name = "anim",
                    color = {0.8, 0.3, 1},
                    offset = {100, 100, 100}
                }
            }
        }
    }
}
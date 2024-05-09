Entities={
    {
        name = "PlayButton",
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
                    name = "play2", 
                    material = "playbutton", 
                    zOrder = 1
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
        name = "Controls",
        components = {           
            {
                name = "UITransformComponent",
                parameters = {                  
                    position = {0.35, 0.05},
                    scale = {0.35, 0.2},
                    hidden = false     
                }
            },
            {        
                name = "UISpriteRendererComponent",
                parameters = {
                    name = "controls", 
                    material = "controls", 
                    zOrder = 1
                }
            }
        }
    },
    {
        name = "ControlsKeyboard",
        components = {           
            {
                name = "UITransformComponent",
                parameters = {                  
                    position = {0.0, 0.2},
                    scale = {0.45, 0.45},
                    hidden = false     
                }
            },
            {        
                name = "UISpriteRendererComponent",
                parameters = {
                    name = "keyboard", 
                    material = "keyboard", 
                    zOrder = 1
                }
            }
        }
    },
    {
        name = "ControlsController",
        components = {           
            {
                name = "UITransformComponent",
                parameters = {                  
                    position = {0.55, 0.2},
                    scale = {0.45, 0.45},
                    hidden = false     
                }
            },
            {        
                name = "UISpriteRendererComponent",
                parameters = {
                    name = "controller", 
                    material = "controller", 
                    zOrder = 1
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
                    name = "background2", 
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
                    name = "controls",
                    color = {0.0, 0.0, 0.0},
                    offset = {0.0, 0.0, 0.0}, 
                    zOrder = 1
                }
            },
            {
                name = "AudioListenerComponent",
                parameters = {

                }
            },
            {
                name = "AudioSourceComponent", 
                parameters ={
                    name = "audioIntro2",
                    path = "sonido_fondo_inicio2.mp3",
                    onstart = true,
                    loop = true,
                    threed = false,
                    volume = 1,
                    groupchannel = "music"
                }
            }
        }
    }
}
Prefabs = {
    {
        name = "PrefabPino",
        components = {
            {
                name = "TransformComponent",
                parameters = {
                    position = {0, 0, 0},
                    rotation = {0, 0, 0},
                    scale = {10000000, 10000000, 10000000}                   
                }
            },
            {
                name = "MeshRenderComponent",
                parameters = {                  
                    isstatic = true,
                    modelname = "Pino.mesh",
                    entityname= "PrefabPino",
                    materialname = ""
                }
            }
        }
    },
    {
        name = "PrefabSmoke",
        components = {
            {
                name = "TransformComponent",
                parameters = {          
                    position = {0, 0, 0},
                    rotation = {0, 90, 0},
                    scale = {5, 5, 5}
                }
            },
            {
                name = "MeshRenderComponent",
                parameters = {                  
                    isstatic = false,
                    modelname = "Humo.mesh",
                    entityname = "Humos",
                    materialname = "SmokeEffect_T"
                }
            },
            {
                name = "SmokeEffect",
                parameters = {
                    particleSystemName = "HumoDisparo",
                    templateName = "SmokeEffect",
                    position = {0, 0, 0},
                    scale = {100, 100, 100},
                    color = {1, 1, 1, 1},
                    duration = 0.5,
                    density = 50
                }
            },
            {
                name = "SmokeComponent",
                parameters = {}
            }
        }
    }
}

Prefabs = {
    {
        name = "PrefabPino",
        components = {
            {
                name = "TransformComponent",
                parameters = {
                    position = {0, 0, 0},
                    rotation = {0, 0, 0},
                    scale = {10, 10, 10}                   
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
                    rotation = {0, 0, 0},
                    scale = {5, 5, 5}
                }
            },
            {
                name = "MeshRenderComponent",
                parameters = {                  
                    isstatic = false,
                    modelname = "Bala.mesh",
                    entityname= "Humos",
                    materialname = "SmokeEffect_T"
                }
            }
            -- {
            --     name = "SmokeEffect",
            --     parameters = {
            --         particleSystemName = "HumoDisparo",
            --         templateName = "SmokeEffect",
            --         position = {-25, 125, 40},
            --         scale = {100, 100, 100},
            --         color = {0, 0, 0, 0},
            --         duration = 1,
            --         density = 50
            --     }
            -- }

        }
    }
}
Prefabs={
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
            },
        }
    }
}

mapping soul_list = ([
        "weapon"        :"����",
        "head"          :"ͷ��",
        "neck"          :"����",
        "cloth"         :"ս��",
        "armor"         :"����",
        "surcoat"       :"����",
        "waist"         :"����",
        "wrists"        :"����",
        "hands"         :"����",
        "boots"         :"սѥ",
        "finger"        :"ָ��",
        "rings"         :"��ָ",
]);
        
void create_soul_file()
{
        string file, filename;
        string *list;
        string id, name;
        int i, n = 0;
        int level, status;

        list = keys(soul_list);

        for( i = 0; i < sizeof(list); i ++ )
        {
                reset_eval_cost();
                for( level = 2; level < 10; level++ )
                {
                        reset_eval_cost();
                        for( status = 1; status < 7; status++ )
                        {
                                id = list[i];
                                name = soul_list[list[i]];
                                filename = id+"_soul"+(level*10)+status;
                 
                                file = read_file("/clone/enchase/equipsoul.h");
                                file = replace_string(file, "RP_NAME", name);
                                file = replace_string(file, "RP_ID", id);
                                file = replace_string(file, "RP_LEVEL", to_string(level*10));
                                file = replace_string(file, "RP_STATUS", to_string(status));

                                write_file("/clone/enchase/" + filename + ".c", file, 1);
                                n++;
                        }
                }
        }

        write(sprintf("%d", n) + " Files created at /clone/enchase/ .\n");
        return;
}


// This program is a part of NITAN MudLIB

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("���", ({ "yiguo"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("prep", "on");
                set("unit", "��");
                set("long", "һ�����δ������������ӡ�\n");
                set("value", 1);
                set("food_remaining", 1);
                set("food_supply", 16);
        }
        setup();
}  
void init()
{
        add_action("do_eat","eat");
}

int do_eat(string arg)
{       
        mapping my; 
        object me = this_player();

        my = me->query_entire_dbase(); 

        if(arg=="yiguo"||arg=="���") {
                message_vision("$N�е������쳣���·����ʲô�鵤��ҩ����\n", me);
                me->set("food",me->max_food_capacity());
                me->set("water",me->max_water_capacity());
                my["jing"]     = my["max_jing"];
                my["qi"]       = my["max_qi"];
                my["eff_jing"] = my["max_jing"];
                my["eff_qi"]   = my["max_qi"];
                my["neili"]    = my["max_neili"];
                my["jingli"]   = my["max_jingli"];

                destruct(this_object());  
                return 1; 
        }        
        return 0;
}
         
           


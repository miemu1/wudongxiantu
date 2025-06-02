// This program is a part of NITAN MudLIB 
// redl 2013/9
//����չ���ҵ����ã�����޷�ʰȡ
#include <ansi.h> 
#include <room.h> 
inherit __DIR__"normal.c"; 

#define CREATE_INTERVAL 120             

int set_lv(object obj, int flag)
{
                if (!flag)
                {
                set("combat/MKS", 2100, obj);
                set("owner/redl", 21000000, obj);
                set("magic/imbue_ok", 1, obj);
                set("magic/blood", 21000, obj);
                set("ultimate/37", 1, obj);
                set("ultimate/39", 1, obj);
                set("enchase/flute", 9, obj);
                set("enchase/SN", 105, obj);
                IDENTIFY_D->identify_ultimate_ob(obj, 1);
                } else
                {
                set("combat/MKS", 2100, obj);
                set("owner/redl", 21000000, obj);
                set("magic/imbue_ok", 1, obj);
                set("magic/blood", 21000, obj);
                set("ultimate/37", 1, obj);
                set("ultimate/39", 1, obj);
                set("enchase/flute", 9, obj);
                set("enchase/SN", 121, obj);
                IDENTIFY_D->identify_ultimate_ob(obj, 1);
            }
        return 1;
}

int do_clear()
{
        object *inv;
        
                        inv = all_inventory();
                        if( sizeof(inv) > 0 ) {
                foreach( object ob2 in inv ) {
                        if( !ob2->is_character() ) {
                                        message_vision(append_color(NOR + CYN + "���������˳��������$N" + NOR + CYN + "����" + (random(2) ? "װ��" : "ɨ��") + "�������\n" + NOR, CYN), ob2);
                                        destruct(ob2); 
                        }
                }
                }
                
        return 1;
}

int create_item()
{
        int rnd, i = random(5) + 4;
        object ob;
        string msg = "";
        
        remove_call_out("create_item");
        remove_call_out("do_clear");
        while (i--) {
                ob = EQUIPMENT_D->create_dynamic("", 60, 600);
        //      rnd = random(100);
//              //if (sscanf(base_name(ob), "/clone/tessera/%*s")) rnd = 100;//�ų���ʯ
//              if (rnd<1) {
//                      CHANNEL_D->channel_broadcast("wiz", "̫��" + base_name(ob) + "\n");
//                      set_lv(ob, 1);
//                      msg = HIK "�ڰ���ɫ��ҫ��أ�̫�ź��" + (random(2) ? "��Ϣ" : "ζ��") + "������Ϣ...\n";
//              }
//              else if (rnd<10) {
//                      CHANNEL_D->channel_broadcast("wiz", "Զ��" + base_name(ob) + "\n");
//                      set_lv(ob, 0);
//                      msg = HIY "�������Ǽ��������Զ������" + (random(2) ? "��Ϣ" : "ζ��") + "��ɢƮ��...\n";
//              }
                ob->move(this_object());
                message_vision(msg + HIC + (random(2) ? "���" : "����") + "~" + (random(2) ? "~" : "") + "~һ����" + 
                                                                                     ob->name() + NOR + HIC + (random(2) ? "�������" : "������") + 
                                                                                     "��" + (random(2) ? "���" : "��Щ") + 
                                                                                      (random(2) ? "�ҵ���ͷ��" : "�䵽�ƺ���") + 
                                                                                      "��¥��" + (random(2) ? "����" : "����") + 
                                                                                      (random(2) ? "����" : "���˵�") + 
                                                                                      (random(2) ? "����" : "������") + "��\n" + NOR, 
                                                                             ob);
        }
        rnd = CREATE_INTERVAL / 2 + random(CREATE_INTERVAL / 2);
        call_out("do_clear", rnd * 9 / 10);
        call_out("create_item", rnd);
        return 1;
}

void create()
{
        set("short", "�칬��¥");
        set("long", 
"�����ƶ�֮�ϵ�һƺ���أ����겻�������׵磬ֻ�����¾�����\n"
"�ַ���ת�����������߲��ľ��¥�󣬾�˵��������Ϊ�����������\n"
"�Ĵ�����¥����Լ�д����ͻ������������š�\n"
);
                set("exits",([ /* sizeof() == 1 */
                        "out" : __DIR__"teleport",
                ]));

        set("no_dazuo",1);
        set("no_kill",1);
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);         
                set("no_rideto", 1);
                set("no_flyto", 1);
                set("no_magic", 1); 
        set("no_sleep_room", 1); 
        //set("no_get", 1);
        set("max_carry_user" ,16);
        set("max_carry_exit" ,"out");
        
        setup();
        call_out("create_item", 3);
}

int do_action(string arg)
{
        string action = query_verb();
        object ob, me = this_player();
        
        if (action=="get") {
                if (!arg || arg=="" || arg=="all") {
                                tell_object(me, NOR "�㵽������ʲô��\n" NOR);
                                return -1;
                        }
                        
                        ob = present(arg, this_object());
                        if (!ob || !objectp(ob)) {
                                        tell_object(me, NOR "����û������������\n" NOR);
                                        return -1;
                        }
                        if (!sscanf(base_name(ob), "/inherit/template/armor/%*s") && !sscanf(base_name(ob), "/inherit/template/weapon/%*s")) {
                                        tell_object(me, NOR "���������ò�������\n" NOR);
                                        return -1;
                        }
                        
                        if (sscanf(base_name(ob), "/inherit/template/weapon/%*s") ||
                                sscanf(base_name(ob), "/inherit/template/armor/finger%*s") ||
                                sscanf(base_name(ob), "/inherit/template/armor/hands%*s")
                                ) {
                                if (query("teleport/tweapon", me) < 1) {
                                        tell_object(me, NOR "�㻹û�й����칬��¥�����һ�ȯ��ָ��<ntstore buy tweapon>��\n" NOR);
                                        return -1;
                                }
                                if (ob->move(me)) {
                                        addn("teleport/tweapon", -1, me);
                                        addn("teleport/log/tweapon", 1, me);
                                        message_vision(NOR "$N�ּ��ۿ죬�ɿ��$n" NOR "�������\n" NOR, me, ob);
                                } else {
                                        tell_object(me, NOR "�����ϳ����ˣ�\n" NOR);
                                }
                                return 1;
                        }
                        
                        if (sscanf(base_name(ob), "/inherit/template/armor/%*s")) {
                                if (query("teleport/tarmor", me) < 1) {
                                        tell_object(me, NOR "�㻹û�й����칬��¥���߶һ�ȯ��ָ��<ntstore buy tarmor>��\n" NOR);
                                        return -1;
                                }
                                if (ob->move(me)) {
                                        addn("teleport/tarmor", -1, me);
                                        addn("teleport/log/tarmor", 1, me);
                                        message_vision(NOR "$N�ּ��ۿ죬�ɿ��$n" NOR "�������\n" NOR, me, ob);
                                } else {
                                        tell_object(me, NOR "�����ϳ����ˣ�\n" NOR);
                                }
                                return 1;
                        }
                }
                
        return 0;
}

void init()
{
        object me = this_player();
        
        if ( wiz_level(me) < 7 ) add_action("do_action", "");
        
        return ::init();
}



// This program is a part of NITAN MudLIB 
// redl 2013/5
#include <ansi.h> 
#include <room.h> 
inherit ROOM; 

void create()
{
                int i = random(4) + 3;
                object ob;
        set("short", "�ֿ�");
        set("long", 
"�����ǻ�������Ĳֿ⣬���������챦���ض����������������ӣ���\n"
"��ҫ�۵��鱦����ɽ������װ����������һ�أ���������û�зŽ�������\n"
"�����и�è�ᣬ���̲�ס������ȥ��һ��(" + CYN + "tao" + NOR + ")��\n"
);
//         set("outdoors", "chengdu");
        set("exits",([ /* sizeof() == 1 */
                "west"   : __DIR__"houdian",
                "down" : __DIR__"dijiao",
        ]));

        set("objects", ([
                "/u/redl/obj/chutou3" : 3,
                "/u/redl/obj/chutou4" : 3,
                      "/clone/wizard/dan" : 2, 
                      "/u/redl/obj/fanghuamu" : 3, 
                      "/u/redl/obj/mbox" : 2, 

        ]));

                set("no_rideto", 1);
                set("no_flyto", 1);
        
        setup();
        
        ob = new("/clone/money/thousand-gold");
        ob->move(this_object());
        ob->set_amount(10000);
        while (i--) {EQUIPMENT_D->create_dynamic("", 60, 600)->move(this_object());}
}


void init()
{
        object me = this_player();
        if ( query("id", me) != "redl" && query("couple/couple_id", me) != "redl" )
        {
                add_action("do_noget", ({"get", "drop", "eat", "smell"}));
        }
        add_action("do_tao", "tao");
}


int do_noget()
{
        tell_object(this_player(), NOR"�㿴�������˰����ɱ����Խ\n"NOR);
        return 1;
}

int do_tao()
{

        object ob, me = this_player();
        if ( me->is_busy() ) {
                        tell_object(me, "�㻹��æ����ͷ�ϵ�������˵�ɡ�\n");
                        return 1;
                }
        message_vision(YEL "$N�������ȥè����ȥ������...\n" NOR, me);
        if ( query("id", me) != "redl" && query("couple/couple_id", me) != "redl" ) 
                {
                        message_vision(YEL "ֻ�������أ�$N" NOR YEL "�ҽ�һ���������������������Ǳ�" HIK "С��è" NOR YEL "ץ����Ŀȫ���ˡ�\n" NOR, me, ob);
                        me->start_busy(5);
                        }
        else 
                {
                                                ob = new(__DIR__"npc/lcat");
                        message_vision(YEL "ֻ��������һ����$N" NOR YEL "��è�������������һֻ�ɰ���$n" NOR YEL "��\n" NOR, me, ob);
                                                ob->move(this_object());
                        ob->command("cat " + query("id", me));
                }

        return 1;
}

void do_start_hslj(string arg)
{
        int type;
        object cat;
        DEBUG_CHANNEL("TIME_D���ñ��� " +(arg?arg:0)+ "�ɹ���\n");
        if (!arg) {
                switch(random(4)) {
                        case 0:
                                message_system(NOR + HIW + "ÿ�£��������գ������㻪ɽ��������[���ű��䳡]�����ƣ���������������֮�䣬��Ʒ��ѫ�º��䶯��;�ң����뼴�к���\n"NOR);
                                break;
                        case 1:
                                message_system(NOR + HIW + "ÿ�£��������գ������㻪ɽ��������[���ű��䳡]�����ƣ�����������������֮�䣬��Ʒ��ѫ�º��䶯��;�ң����뼴�к���\n"NOR);
                                break;
                        case 2:
                                message_system(NOR + HIW + "ÿ�£��գ������㻪ɽ��������[���ű��䳡]�����ƣ�������֮�ϣ���Ʒ��ѫ�º��䶯��;�ң����뼴�к���\n"NOR);
                                break;
                        case 3:
                                message_system(NOR + HIW + "ÿ�£��գ������㻪ɽ��������[��ɽ�۽����䳡]����������װ������Ʒ��ѫ�º��䶯��;�ң����뼴�к���\n"NOR);
                                break;
                }
                return;
        }
        
        cat = new(__DIR__"npc/lcat");
                cat->move(this_object());
        cat->do_start_hslj(arg);
}

void callout_hslj(string arg) 
{
        int delay;
        if (!arg || sscanf(arg, "%s %d", arg, delay) != 2) return;
        call_out("do_start_hslj", delay, arg);       
}

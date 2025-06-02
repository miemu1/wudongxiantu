// This program is a part of NITAN MudLIB 
// redl 2013/5
#include <ansi.h> 
#include <room.h> 
inherit ROOM; 


string look_bi(object me)
{
        me->remove_call_out("do_open");
        call_out("do_open", 6, me); 
        return "\n"
HIK 
"��һֱ��Ҫ ����һ�� ��������������ɽ·\n"
"����� �а��� ������������\n"
"�����ҿ��ֺ͸м�����\n"
"�ҵ�Ҫ����ʵ��΢С ֻҪ�й�������һ������\n"
"ֻҪ�߹� ������һ��\n"
"������ӭ���� �ո���ҹ ȴ����һЩ�����ϵ��İ���\n"
"�������������Ĵ��� �����������������ظ���\n"
"�ý�ҹ���� �������\n"
"���еı������ѳɻҽ� ��������һ��·�Ҷ�����\n"
"����ͬ��\n"
HIW 
"           ��޲��糱���š���˼ʼ��������\n"
"\n" NOR;
}


void create()
{
        set("short", "�κ�");
        set("long", 
"�������ǰ��һ��С������ˮ�����Թ⣬������Ĵ������ߵ�ϸɳ��\n"
"͸���峺�ĺ�ˮ������Կ�����ˮ����Ϸ����Ϻ����������ˮ���������\n"
"��ˮ�ݡ�������һЩ�де���ľ��������һ���������Ƶľ�"CYN"��"NOR"��\n"
);
//         set("outdoors", "chengdu");
         set("exits",([ /* sizeof() == 1 */
                 "east" : __DIR__"lakeroad",
         ]));

        set("item_desc", ([
                "����": (: look_bi :),
                "��": (: look_bi :),
                "bi": (: look_bi :),
        ]) );

                set("no_rideto", 1);
                set("no_flyto", 1);
                      set("no_magic", 1); 
        
        setup();
        
                remove_call_out("do_wave");
                call_out("do_wave", 5);        
}

int do_wave()
{
                switch(random(11)) {
                        case 0:
                        case 1:
                        case 2:
                        case 3:
                        tell_room(this_object(), CYN "�֡�"NOR HIG "һ��΢�紵�����κ����淺����ǧ�ٲ����Ա̲���\n" NOR);
                        break;
                        case 4:
                        case 5:
                        case 6:
                        tell_room(this_object(), CYN "�֡�"NOR HIW "��ˮ��ɳ̲�����ǽ��䣬��Ҳ�Ƴ������಻����\n" NOR);
                        break;
                        case 7:
                        case 8:
                        tell_room(this_object(), CYN "�֡�"NOR HIC "�����������ɳ̲����������������ǹ���Ľ�ֺ��\n" NOR);
                        break;
                        case 9:
                        tell_room(this_object(), CYN "�֡�"NOR HIY "һ�����˴�������ʪ����ʯС�ף���������ȴ��\n" NOR);
                        break;
                case 10:
                        tell_room(this_object(), CYN "�֡�"NOR HIB "������ľҡҷɳɳ���죬���ĵ��ϵ�ľ��ȴ���������\n" NOR);
                        break;
            }
        call_out("do_wave", 30 + random(20));              
        return 1;
}

void do_open(object me)
{
        if (environment(me)!=this_object()) return;
        tell_object(me, YEL "����˼���ţ���˭��Ī���ָ����ʯ���Ͽ��飿\n" NOR);
        me->remove_call_out("do_open2");
        call_out("do_open2", 8, me); 
        me->remove_call_out("do_close");
        call_out("do_close", 16, me); 
}

void do_open2(object me)
{
        if (environment(me)!=this_object()) return;
        tell_object(me, YEL "����ͻȻ���Ҷ�����������ֻ���������¶��һ��ɽ������\n" NOR);
        set("exits/west", __DIR__"lakecave");
}

void do_close(object me)
{
        if (environment(me)!=this_object()) return;
        tell_object(me, YEL "����һ���ɣ������ɽ����ڻָ������\n" NOR);
        delete("exits/west");
}





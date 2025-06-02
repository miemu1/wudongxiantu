// This program is a part of NITAN MudLIB 
// redl 2013/5
#include <ansi.h> 
#include <room.h> 
inherit ROOM; 

void create()
{
        set("short", "��ʯС��");
        set("long", 
"����һ����ʯ���̾͵�·������ں�ˮ�У���������ĵ�С���ϡ���\n"
"������ŵ���ʮ����ʯ�Ŷ�֮����ʯС������ת���ϣ������ɼ����ּ�\n"
"�З�ľ�ݡ�\n"
);
         //set("outdoors", "chengdu");
        set("exits",([ /* sizeof() == 1 */
                "eastup" : __DIR__"lakehouse",
                "west" : __DIR__"lake",
        ]));

                set("no_rideto", 1);
                set("no_flyto", 1);
                      set("no_magic", 1); 
        
        setup();
        
        
                remove_call_out("do_wave");
                call_out("do_wave", 10);        
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
        call_out("do_wave", 11 + random(5));              
        return 1;
}




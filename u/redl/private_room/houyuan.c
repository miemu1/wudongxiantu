#include <ansi.h>
#include <room.h>

inherit PRIVATE_ROOM;

void create()
{
        set("short", "����������");
        set ("long", 
" "HIY"��" NOR "\n"
"    ��"HIY"��"NOR"����"HIY"��"NOR"��"MAG"�λ���ɽ�����ơ��ٵ��׺�������" NOR "\n"
"    ��������������������������"CYN"�֡�"NOR"����"HIY"��"NOR"����" NOR "\n"
"    ����"CYN"��"NOR"����/��\\ �񡡡��� "CYN"�� �֡�"NOR"������" NOR "\n"
"    ��"CYN"�֡֡�"NOR"��/��\\/��\\����"CYN"�֡֡֡֡֡�"NOR"����" NOR "\n"
"    �n�T�n�T�n <|��||���T�T�n�T�n�T�n�T�n��" NOR "\n"
"    ------------------------------         " NOR "\n"
"    ������ңң������Զ���ı̺������׵������������������ζ���" NOR "\n"
);

        setup();

        set("exits", ([
                "south"  : "/u/redl/houdian",
                "east"  : __DIR__"woshi",
                "north"  : "/u/redl/swing",
                "westup" : "/u/redl/suiroad1",
        ]));

        set("outdoors", "chengdu");
        //set("sleep_room", 1);
                //set("no_fight", 1); 
                set("no_rideto", 1);
                set("no_flyto", 1);

        set("room_owner", "��������");
        set("room_name", "����");
        set("room_id", "redl");
        set("room_owner_id", "redl");
        set("room_position", "Ϫ��С·");
}

int valid_leave(object me, string dir)
{
        if ((dir == "north" || dir == "east") && (query("id", me) != "redl" && query("couple/couple_id", me) != "redl"))
                return notify_fail("������˽�˵ط����ܹ�ȥ��\n");

        return ::valid_leave(me, dir);
}


#include <ansi.h>
inherit ROOM;

int is_chat_room() { return 1; }

void create()
{
        set("short", HIY "����ҳά�������ҡ�" NOR);
        set("long", @LONG
��������ҳά����Ա�����ĵط�������ɢ���Ÿ���ֽƬ������
����д���Ź�����¼��
�뽫�������post�����԰棬��ʦ�ᶨ�ڲ�ѯ��
LONG
);

        set("exits", ([
                "out" : "/d/city/kedian",                
        ]));

        set("valid_startroom", 1);
        set("sleep_room", 1);
        set("no_fight", 1);

        setup();
        "/clone/board/webmaster_b"->foo();
}



#include <room.h>
inherit TRANS_ROOM; 

void create()
{
        set("short", "������վ");
        set("long",
"����һ����ľ��Ӵ�ľ�������һ��С����װ�εĻ��㲻��һ��Ц\n"
"�����Ļ��վ��������������æ�����к�����̨������һ�����ţ���\n"
"�����ţ����洫�����˻��������������������Ϳ���(paizi)�ɡ�\n"
);

        set("valid_startroom", 1);

        set("exits", ([
                 "east" : __DIR__"bdajie1",
        ]));
        set("objects", ([
                "/d/tangmen/npc/tmxer" : 1,
        ]));

        set("area", "����");
        set("che_id", "tmmache");

        setup();
}


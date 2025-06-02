// xiaoyuan.c

#include <ansi.h>
inherit "/inherit/room/house_door";

void create()
{
    set("short", "��լ����");
    set("long", @LONG
��ǰ�ô�һƬլԺ������¥̨��������ǽ���ѣ���֪ռ���ж���Ķ��
��������Ʈ�����ƣ����������ƻã������������С�
LONG);

    set("exits",
    ([
        "out"   : __FILE__,
        "north" : __DIR__"qianyuan",
    ]));

    set("owner_name", "ĳ��");
    set("owner", "OWNER");
    set("huyuan", __DIR__"huyuan");
    set("outdoors", "OUTDOORS");
    set("forbid_exits", "north");
    set("max_laodu", 1000000);
    set("now_laodu", 1000000);

    setup();
    restore();
}

int valid_leave(object me, string dir)
{
    if(dir != query("forbid_exits"))
        return ::valid_leave(me, dir);

    if(!wizardp(me)
        && me->query("id") != query("owner")
        && me->query("couple/couple_id") != query("owner")
        && !me->query_temp("invited_guest/" + query("owner")))
            return notify_fail(WHT "ǰ���ƺ���һ�����ε�������ס��"
                                   "������Ҳ�޷�ǰ�а�֡�\n" NOR);

    message_vision(HIC "\nһƬ����Ʈ�������Ὣ$N����"
                       "ƮƮ���Ƶط��˽�ȥ��\n" NOR, me);
    return ::valid_leave(me, dir);
}

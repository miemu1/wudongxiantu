// houyuan.c

inherit "/inherit/room/house_room";

void create()
{
    set("short", "��Ժ");
    set("long", @LONG
����լ�ӵĺ�Ժ������һ����ɽ����Ȼ���������Ʋ���������
��ˮ���ȣ���ɽ���ߣ���Ȼ��Ϣ��
LONG);

    set("exits",
    ([
        "south" : __DIR__"houting",
    ]));

    set("outdoors", "OUTDOORS");
    set("owner", "OWNER");
    set("owner_name", "ĳ��");
    set("resource/water", "Ȫˮ");

    setup();
    restore();
}

// ting.c

inherit "/inherit/room/house_room";

void create()
{
    set("short", "����");
    set("long", @LONG
������λ�ڻ�԰����һ���������������д�֪�����ѵĵط�������
�������£���ɨ���˳���Ⱦ����������ի���������ٷ���¥���������˵�
���ҡ�
LONG);

    set("exits",
    ([
        "west"  : __DIR__"qinfang",
        "east"  : __DIR__"shuzhai",
        "up"    : __DIR__"wofang",
        "north" : __DIR__"houyuan",
        "south" : __DIR__"huayuan",
    ]));

    set("no_learn", 1);
    set("owner", "OWNER");
    set("owner_name", "ĳ��");
    set("resource/water", "��ˮ");
    setup();
    restore();
}

// This program is a part of NITAN MudLIB

inherit ROOM;

void create()
{
        set("short", "����"); 
        set("long", @LONG
����������ɽׯ�����ҡ����Ӳ���Ҳûʲô���裬���߰�����
��Щ�������õľ����ǽ�ǲ�����֩�����������Ӷ��ǻҳ���Ǻ��
�㲻ס���ԡ�
LONG );
        set("type","indoors");
        set("exits",([
                "east":__DIR__"grass4",
                "south":__DIR__"grass1",
        ]) ); 

		    set("objects",([
                CLASS_D("mojiao/qingqing") : 1,
        ]));

        set("coor/x",-600);
        set("coor/y",250);
        set("coor/z",80);
        setup();
        replace_program(ROOM);
}      

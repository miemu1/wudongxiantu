// This program is a part of NITAN MudLIB

inherit ROOM; 
void create()
{
        set("short", "����ƺ"); 
        set("long", @LONG
������һ�鷼��ƺ���̲����𣬺������裬�����˱ǣ����˸е�
ʮ����⡣�������˾���һͷ�ɵ���ȥ���úõ�ȥ˯һ����������ż
��Ҳ�������˻��ߡ�
LONG );
        set("type","grassland");
        set("outdoors", "fugui");
        set("exits",([
                "east":__DIR__"grass3",
                "west":__DIR__"grass1",
        ]) );
        set("objects",([
               "/clone/beast/caihuashe" : 1,
                __DIR__"obj/greengrass" : 1,
        ]) );
        set("coor/x",-590);
        set("coor/y",240);
        set("coor/z",80);
        setup();
        replace_program(ROOM);
}

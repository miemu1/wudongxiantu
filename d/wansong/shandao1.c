// This program is a part of NITAN MudLIB

inherit ROOM;
void create()
{
        set("short", "ɽ��"); 
        set("long", @LONG
���˴˴���ɽ�ƽ���ƽ̹Щ���ѿɴ��¿�����Զ������ɽׯ��
����һ��������ɽ���ϵķ��ӣ����Ӻܴ󣬽����ú��ûʡ���ʾ����
һ������Ǯ�������Ӿ���С��Ҳ̫Զ��Щ��Ҳ̫ƫƧ��Щ��������ֱ
��˵�ǻ������̡�
LONG );
        set("outdoors", "wansong");
        set("type","road");
        set("exits",([
                "north": "/d/xingxiu/shanjiao",
                "south":__DIR__"shandao2",
        ]) );

        set("coor/x",-590);
        set("coor/y",190);
        set("coor/z",70);
        setup();
        
} 

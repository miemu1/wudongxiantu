inherit ROOM;
void create()
{
        set("short", "��ھ�����"); 
        set("long", @LONG
������ã������������˴˴������Ȼ���ʣ��ѿ�վֱ������
�㶨��һ�ƣ�������ʧɫ�����л�Ȼ�����������ɣ�����ˮͰ�Ľ�
�ھ����������У�һ�Ա�����棬˸Ȼ�Ź⡣���к��Ǳ�أ��ȳ���
�����������
LONG );
        set("indoors", "wansong");
        set("type","mountain");
        set("exits",([
                "south":__DIR__"shandong",
			"west":__DIR__"dong0",
        ]) );
        set("objects", ([
                "/clone/beast/xuanmang" : 1,
                __DIR__"obj/skeleton" : 2,
        ]) ); 
        set("coor/x",-610);
        set("coor/y",300);
        set("coor/z",80);
        set("refresh_all_items", 1);
        setup();
} 

// This program is a part of NITAN MudLIB

inherit ROOM;

void create()
{
        set("short", "����԰");
        
        set("long", @LONG
�����������������ܾ��Ǵ���԰��������������ÿ�������°�
����ҹ������ɽׯ�����������Ǳ�����ˣ�һ�����Σ�һ����裬��
�Ǻ��˰������������ϧ�����ɺܾ��Ѿ�û��������ˣ����ǻ�ʱ��
�������ֵ��ǿ�����Ǯ���ƣ��긴һ�꣬����԰�е�����ҲԽ��Խ�١�
LONG );
        set("outdoors", "wansong");
        set("type","forest");
        set("exits",([
                "south":__DIR__"wuzhuxuan",
        ]) );

        set("coor/x",-610);
        set("coor/y",230);
        set("coor/z",80);
        setup();
} 
 

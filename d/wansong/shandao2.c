inherit ROOM;

void create()
{
        set("short", "ɽ��"); 
        set("long", @LONG
������ȥ����ɽׯ��ɽ���ϣ�һ̧ͷ���ֿɿ��������������״��
������ӥ״�ķ��ݸ߸߷�������������С�ɽ�����죬�������ƣ���
���о������Եá�������̽ͷ��ȥ���ѿ���Լ��������ɽׯ��ͭ���
�š�
LONG );
        set("outdoors", "wansong");
        set("type","road");
        set("exits",([
                "westup":__DIR__"damen",
                "north":__DIR__"shandao1",
        ]) );
        

        set("coor/x",-590);
        set("coor/y",180);
        set("coor/z",60);
        setup();
} 

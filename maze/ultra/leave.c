inherit ROOM;

void create()
{
        set("short", "�Թ�����");
        set("long", @LONG
����һ�����ʯ�ݣ����ܾ�ʯ�ݾ͵�ǽ�ڷ������ĵ���ɫ��â����յ��ͭ
���³�һ�߸ߵĻ��棬Ʈ����˸��żȻ�еƻ����ѵ����죬�����˸е���Ϣ���
�ž��������������������ʯ���̾ͣ���������һ���ɫʯ�������Ŀ�������
����ϸ�ܵ�ͼ�ƣ����˲�������������ǰ�鿴��mazemap��һ����
LONG );
        set("no_clean_up", 1);
        set("no_drop", 1);
        set("no_sleep_room", 1);
        set("no_magic", 1);
        set("virtual_room",1);
        set("exits", ([
                "east":__DIR__"maze/exit", 
                "out": "/d/city/wumiao", 
        ]));  
                    
        setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "out" && userp(me) && query("exits/out"))
        {
                FUBEN_D->clear_fuben("ultra", query("id", me));
        }
        
        return ::valid_leave(me, dir);
}


inherit ROOM; 

void create() 
{ 
        set("short", "��Į����"); 
        set("long", @LONG 
һ���޼ʵĴ�Į�����ա���ɳ���ຮ�����ȣ���ʱ������ĥ��ÿ
һ���ˣ�����������û����ˮ�����п��ܾͻᱻɹ����ɳ�ӹ��̣�
���԰ѽ����ã�һ�����ϣ�ȴ�ֱ����͸�ǡ�

LONG
); 
                        
        set("outdoors", "desert"); 
        set("no_magic",1);
        set("exits", ([ /* sizeof() == 3 */ 
                "north":__DIR__"maze/exit",
                "out": "/d/luoyang/wenmiao",
        ])); 
                        
        setup();
        // replace_program(ROOM); 
} 

/*
int valid_leave(object me, string dir)
{
        object *inv, obj;
        int ret;

        if (dir == "out")
        {
                //FUBEN_D->query_maze_mainobj(me)->refresh_maze();
                if( ret=query_temp("fuben_event", me) )
                {
                        SCHEDULE_D->delete_event(ret);
                        FUBEN_D->clear_fuben("desert",query("id", me));
                }
        }
        return 1;
}
*/

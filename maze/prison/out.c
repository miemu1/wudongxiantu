inherit ROOM; 

void create() 
{ 
        set("short", "���γ���"); 
        set("long", @LONG 
����ڳ����ģ�����һ˿������Ҳ�ް����Ϣ���ڰ�����ϡ����
��������ƺ��м�����Ӱ��������ת��ͷȥ������������ס��������
�ŵص����㡣�ı�����ȥ�������Ҽ�Ӳ���ƺ����Ǹ������ɡ��ű���
һ�Ѷ�������ȥ�����ݵ�ɢ�˿�����ϸ��ȴ��һ�߰׵÷����Ŀݹǡ�
LONG
); 
                        
        set("outdoors", "necropolis"); 
        set("virtual_room", 1);
        set("no_magic", 1);
        set("exits", ([ /* sizeof() == 3 */ 
                "north":__DIR__"maze/exit",
                "out"  : "/d/beijing/hg_w",
        ])); 
                        
        setup();

} 
int valid_leave(object me, string dir)
{
        object *inv, obj;
        if (dir == "out")
        {
                tell_object(me, "check!\n");
                inv = all_inventory(me);
                if (inv && sizeof(inv)>0)
                        foreach(obj in inv) {
                                if (obj && obj->query("maze_item"))
                                        destruct(obj);
                        }
        }
        return 1;
}


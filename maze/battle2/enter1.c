inherit ROOM; 
void create() 
{ 
        set("short", "ս�����"); 
        set("long", @LONG 
����Խ��Խ���ˣ��㵨���ľ�����ǰ�����ţ�������һЩ
��·�˵�ʬ������á���ʱ����һ�������˺�,������ʲô
�����ڰ��п����ţ��㲻�ɵļӿ��˽Ų���
LONG
); 
                        
        set("outdoors", "battle"); 
        set("virtual_room", 1); 
        set("no_magic",1);
        set("exits", ([ /* sizeof() == 3 */ 
                "west" : __DIR__"maze/entry", 
        ])); 

        setup();
        replace_program(ROOM); 
} 

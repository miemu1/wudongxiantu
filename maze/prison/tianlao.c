inherit ROOM; 

void create() 
{ 
        set("short", "�������"); 
        set("long", @LONG 
����ڳ����ģ�����һ˿������Ҳ�ް����Ϣ���ڰ�����ϡ����
��������ƺ��м�����Ӱ��������ת��ͷȥ������������ס��������
�ŵص����㡣�ı�����ȥ�������Ҽ�Ӳ���ƺ����Ǹ������ɣ�ֻ����
�������һ��С�ţ����Ͽ��˸����ƴ�Ķ��������ͷ��õġ��ű���
һ�Ѷ�������ȥ�����ݵ�ɢ�˿�����ϸ��ȴ��һ�߰׵÷����Ŀݹǡ�
LONG
); 
                        
        set("outdoors", "prison"); 
        set("virtual_room", 1);
        set("no_death", 1);
        set("no_magic", 1);
        set("exits", ([ /* sizeof() == 3 */ 
                "south" : __DIR__"maze/entry", 
        ])); 
        set("objects",([
                "/maze/prison/prison_door" : 1,
        ])); 
        setup();
 
} 


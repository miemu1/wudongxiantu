#include <ansi.h>

inherit VRM_SERVER;

//#define ENTER_ROOM_X  0
//#define ENTER_ROOM_Y    0
//#define ENTER_ROOM_Z    0

void create() 
{ 
        // �Թ��������̳е�����ĵ������ơ� 
        set_inherit_room( ROOM );  
                        
        //�Թ�������Ĺ�� 
        set_maze_npcs( ([
                "/maze/prison/npc/qiutu1": 1 + random(2),
                "/maze/prison/npc/qiutu2": 1 + random(2),
                "/maze/prison/npc/qiutu3": 1 + random(2),
                "/maze/prison/npc/jinyiwei": 1 + random(2),
        ]) );                   

        set_exit_npcs( "/maze/prison/npc/laotou" );
        //��������              
        //set_no_death_room(1);
        
        //�Թ��ĵ��߳� 
        set_maze_long(8); 
                        
        //��ڷ���(�����ڶ���) 
        set_entry_dir("north"); 
                        
        //�������������ӷ��� 
        set_link_entry_dir("north"); 
                        
        //�������������ӵ����� 
        set_link_entry_room(__DIR__"enter"); 
                        
        //��������������ӷ��� 
        set_link_exit_dir("south"); 
                        
        //��������������ӵ����� 
        set_link_exit_room(__DIR__"out"); 
                        
        //�������������
        //set_link_entry_room_x(ENTER_ROOM_X);
        //set_link_entry_room_y(ENTER_ROOM_Y);
        //set_link_entry_room_z(ENTER_ROOM_Z);
                        
        //��ͨ��������
        set_maze_room_short(RED "����" NOR);
                        
        set_maze_room_desc(@LONG
����ڳ����ģ�����һ˿������Ҳ�ް����Ϣ���ڰ�����ϡ����
��������ƺ��м�����Ӱ��������ת��ͷȥ������������ס��������
�ŵص����㡣�ı�����ȥ�������Ҽ�Ӳ���ƺ����Ǹ������ɡ��ű���
һ�Ѷ�������ȥ�����ݵ�ɢ�˿�����ϸ��ȴ��һ�߰׵÷����Ŀݹǡ�
LONG); 
                        
        //��ڷ�������� 
        set_entry_short(HIR "�������" NOR); 
                        
        //��ڷ������� 
        set_entry_desc(@LONG
����ڳ����ģ�����һ˿������Ҳ�ް����Ϣ���ڰ�����ϡ����
��������ƺ��м�����Ӱ��������ת��ͷȥ������������ס��������
�ŵص����㡣�ı�����ȥ�������Ҽ�Ӳ���ƺ����Ǹ������ɡ��ű���
һ�Ѷ�������ȥ�����ݵ�ɢ�˿�����ϸ��ȴ��һ�߰׵÷����Ŀݹǡ�
LONG); 
                        
        //���ڷ�������� 
        set_exit_short(HIW "���γ���" NOR); 
                        
        //���ڷ������� 
        set_exit_desc(@LONG
����ڳ����ģ�����һ˿������Ҳ�ް����Ϣ���ڰ�����ϡ����
��������ƺ��м�����Ӱ��������ת��ͷȥ������������ס��������
�ŵص����㡣�ı�����ȥ�������Ҽ�Ӳ���ƺ����Ǹ������ɡ��ű���
һ�Ѷ�������ȥ�����ݵ�ɢ�˿�����ϸ��ȴ��һ�߰׵÷����Ŀݹǡ�
LONG); 

        // �Թ������Ƿ�Ϊ���ⷿ�䣿 
        // set_outdoors(1); 
        
} 



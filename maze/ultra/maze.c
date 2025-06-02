#include <ansi.h>
inherit "/adm/daemons/vrm_server.c";

#define ENTER_ROOM_X  0
#define ENTER_ROOM_Y  0
#define ENTER_ROOM_Z  0
 
void create() 
{ 
        set_lonely_create(1);
        
        //�Թ��������̳е�����ĵ������ơ� 
        set_inherit_room( ROOM ); 
        
        //�Թ��ĵ��߳� 
        set_maze_long(8); 
        
        set_maze_boxs(3);
        
        //set_maze_traps(3);
                        
        //��ڷ���(�����ڶ���) 
        set_entry_dir("east"); 
                        
        //��������������ӷ��� 
        set_link_exit_dir("west"); 
                        
        //��������������ӵ����� 
        set_link_exit_room(__DIR__"leave"); 

        //������������� 
        set_link_entry_room_x(ENTER_ROOM_X); 
        set_link_entry_room_y(ENTER_ROOM_Y); 
        set_link_entry_room_z(ENTER_ROOM_Z); 
                        
        //��ͨ��������
        set_maze_room_short("�Թ�");
                        
        set_maze_room_desc(@LONG
����һ�����ʯ�ݣ����ܾ�ʯ�ݾ͵�ǽ�ڷ������ĵ���ɫ��â����յ��ͭ
���³�һ�߸ߵĻ��棬Ʈ����˸��żȻ�еƻ����ѵ����죬�����˸е���Ϣ���
�ž��������������������ʯ���̾ͣ���������һ���ɫʯ�������Ŀ�������
����ϸ�ܵ�ͼ�ƣ����˲�������������ǰ�鿴��mazemap��һ����
LONG); 

        //��ڷ�������� 
        set_entry_short("�Թ����"); 
                        
        //��ڷ������� 
        set_entry_desc(@LONG
����һ�����ʯ�ݣ����ܾ�ʯ�ݾ͵�ǽ�ڷ������ĵ���ɫ��â����յ��ͭ
���³�һ�߸ߵĻ��棬Ʈ����˸��żȻ�еƻ����ѵ����죬�����˸е���Ϣ���
�ž��������������������ʯ���̾ͣ���������һ���ɫʯ�������Ŀ�������
����ϸ�ܵ�ͼ�ƣ����˲�������������ǰ�鿴��mazemap��һ����
LONG);
                        
        //���ڷ�������� 
        set_exit_short("�Թ�����"); 
                        
        //���ڷ������� 
        set_exit_desc(@LONG
����һ�����ʯ�ݣ����ܾ�ʯ�ݾ͵�ǽ�ڷ������ĵ���ɫ��â����յ��ͭ
���³�һ�߸ߵĻ��棬Ʈ����˸��żȻ�еƻ����ѵ����죬�����˸е���Ϣ���
�ž��������������������ʯ���̾ͣ���������һ���ɫʯ�������Ŀ�������
����ϸ�ܵ�ͼ�ƣ����˲�������������ǰ�鿴��mazemap��һ����
LONG);
 
        // �Թ�������߽���ȼ�
        set_remove_time(1800); 
} 



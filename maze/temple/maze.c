// This program is a part of NITAN MudLIB

#include <ansi.h>

inherit VRM_SERVER;

void create() 
{ 
        //�Թ��������̳е�����ĵ������ơ� 
        set_inherit_room( ROOM );  
                        
        //Ψһ����
        set_unique_room( ({
                "/maze/temple/unique_room/zombie_room",
        }) ); 

        //�Թ�������Ĺ�� 
        set_maze_npcs( ([
                "/maze/temple/npc/zombie": 3,  
                "/maze/temple/npc/zombie_lord": !random(5),
        ]) );
        
        set_lonely_create(1);
        
        //set_maze_boxs(6); 
        
        //set_maze_traps(6); 

        //�Թ��ĵ��߳� 
        set_maze_long(10); 
                        
        //��ڷ���(�����ڶ���) 
        set_entry_dir("north"); 
                        
        //�������������ӷ��� 
        set_link_entry_dir("north"); 
                        
        //�������������ӵ����� 
        set_link_entry_room("/d/city/wumiao"); 
                        
        //��������������ӷ��� 
        set_link_exit_dir("south"); 
                        
        //��������������ӵ����� 
        set_link_exit_room("/d/city/wumiao"); 
                        
                        
        //��ͨ��������
        set_maze_room_short(RED "ʧ������" NOR);
                        
        set_maze_room_desc(@LONG
����ܴ������ϵ����ǧ��ٹֵĶ���е�������ȴ
����һ����ͷ������������һ˫��򣬹���Ĺ��׵ĵ������
̾Ϊ��ֹ�����ɰ˽ǣ��ݼ���������,����,���,ľ��,�ʻ�
��Ϊ��Ʒ��
LONG); 
                        
        //��ڷ�������� 
        set_entry_short(HIR "ʧ���������" NOR); 
                        
        //��ڷ������� 
        set_entry_desc(@LONG
����ܴ������ϵ����ǧ��ٹֵĶ���е�������ȴ
����һ����ͷ������������һ˫��򣬹���Ĺ��׵ĵ������
̾Ϊ��ֹ�����ɰ˽ǣ��ݼ���������,����,���,ľ��,�ʻ�
��Ϊ��Ʒ��
LONG); 
                        
        //���ڷ�������� 
        set_exit_short(HIW "ʧ���������" NOR); 
                        
        //���ڷ������� 
        set_exit_desc(@LONG
����ܴ������ϵ����ǧ��ٹֵĶ���е�������ȴ
����һ����ͷ������������һ˫��򣬹���Ĺ��׵ĵ������
̾Ϊ��ֹ�����ɰ˽ǣ��ݼ���������,����,���,ľ��,�ʻ�
��Ϊ��Ʒ��
LONG); 
                                              
} 


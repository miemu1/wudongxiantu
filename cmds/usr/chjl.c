
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	    object ob1;
        int min, hrs, day, mon, age;
        me=this_player();
        
        if (! arg || arg == "")
                return notify_fail("��Ҫ����ʲô�ƺţ�\n");
                         
        if (me->is_fighting())
                return notify_fail("����æ�Ŵ���أ�����ʱ���������£�\n");

        if (me->is_busy())
                return notify_fail("����æ��û������������\n");
                					
					
		if (arg == "quxiao")
        {
                        
                
                me->delete("chjh");
		    	me->delete("chjl");
		    	me->delete("title");
                me->delete("chenghao");
			    me->delete("titlea");
            write(HIR"ȡ��ǰ׺�ƺųɹ�������Լ��������ƺ��ˡ�\n");
        }			 
		if (arg == "quxiao1")
        {
                        
                
                me->delete("chenjch");
//		    	me->delete("chjl");
//		    	me->delete("title");
//               me->delete("chenghao");
			
            write(HIR"ȡ�³ɾͳƺųɹ�������Լ��������ɾͳƺ��ˡ�\n");
        }	
		
         if (arg == "������")
        {        
                if (!me->query("titles/������"))
                    return notify_fail("�㻹δ�������ɾͳƺš�\n"); 
				if(me->query("chenjch"))
				    return notify_fail("����ȡ�µ�ǰ�ɾͳƺ��ټ��\n"); 	      
                me->set("chenjch",HIC"[������]"NOR);
            write(HIR"����ɾͳƺųɹ���\n");
        }
         if (arg == "������")
        {        
                if (!me->query("titles/������"))
                    return notify_fail("�㻹δ�������ɾͳƺš�\n"); 
				if(me->query("chenjch"))
				    return notify_fail("����ȡ�µ�ǰ�ɾͳƺ��ټ��\n"); 	      
                me->set("chenjch",HIC"[������]"NOR);
            write(HIR"����ɾͳƺųɹ���\n");
        }


         if (arg == "slr")
        {
                        
                if (!me->query("chenghao/slr"))
                    return notify_fail("�㻹δ�������ƺš�\n"); 
					
				if(me->query("chjh"))
				    return notify_fail("����ȡ�µ�ǰ�ƺ��ټ��\n"); 	    
                    
                me->add("chjh",1);
		    	me->add("chjl/str",5);
		    	me->add("chjl/int",5);
		    	me->add("chjl/con",5);
		    	me->add("chjl/dex",5);
				me->add("chjl/max_jing",500);
		    	me->add("chjl/max_qi",500);
		    	me->add("chjl/max_jingli",500);	
		    	me->add("chjl/max_neili",10);
		    	me->set("title",HIY"������"NOR);
                 
			
            write(HIR"����ƺųɹ���\n");
        }
        if (arg == "zmjh")
        {
                        
                if (!me->query("chenghao/zmjh"))
                    return notify_fail("�㻹δ�������ƺš�\n"); 
					
				if(me->query("chjh"))
				    return notify_fail("����ȡ�µ�ǰ�ƺ��ټ��\n");	    
                    
                me->add("chjh",1);
		    	me->add("chjl/str",5);
		    	me->add("chjl/int",5);
		    	me->add("chjl/con",5);
		    	me->add("chjl/dex",5);
				me->add("chjl/max_jing",500);
		    	me->add("chjl/max_qi",500);
		    	me->add("chjl/max_jingli",500);	
		    	me->add("chjl/max_neili",10);
		    	me->set("title",HIM"������"NOR);
                			
            write(HIR"����ƺųɹ���\n");
        } 

        return 1;
}


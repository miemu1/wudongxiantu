
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
		
         if (arg == "�������")
        {        
                if (!me->query("titles/�������"))
                    return notify_fail("�㻹δ�������ɾͳƺš�\n"); 
				if(me->query("chenjch"))
				    return notify_fail("����ȡ�µ�ǰ�ɾͳƺ��ټ��\n"); 	      
                me->set("chenjch",HIC"[�������]"NOR);
            write(HIR"����ɾͳƺųɹ���\n");
        }
         if (arg == "����֮��")
        {        
                if (!me->query("titles/����֮��"))
                    return notify_fail("�㻹δ�������ɾͳƺš�\n"); 
				if(me->query("chenjch"))
				    return notify_fail("����ȡ�µ�ǰ�ɾͳƺ��ټ��\n"); 	      
                me->set("chenjch",HIC"[�������]"NOR);
            write(HIR"����ɾͳƺųɹ���\n");
        }
         if (arg == "��ħ�޽�")
        {        
                if (!me->query("titles/��ħ�޽�"))
                    return notify_fail("�㻹δ�������ɾͳƺš�\n"); 
				if(me->query("chenjch"))
				    return notify_fail("����ȡ�µ�ǰ�ɾͳƺ��ټ��\n"); 	      
                me->set("chenjch",HIC"[��ħ�޽�]"NOR);
            write(HIR"����ɾͳƺųɹ���\n");
        }
         if (arg == "̫������")
        {        
                if (!me->query("titles/̫������"))
                    return notify_fail("�㻹δ�������ɾͳƺš�\n"); 
				if(me->query("chenjch"))
				    return notify_fail("����ȡ�µ�ǰ�ɾͳƺ��ټ��\n"); 	      
                me->set("chenjch",HIC"[̫������]"NOR);
            write(HIR"����ɾͳƺųɹ���\n");
        }
        if (arg == "��ʥ")
        {        
                if (!me->query("titles/��ʥ"))
                    return notify_fail("�㻹δ�������ɾͳƺš�\n"); 
				if(me->query("chenjch"))
				    return notify_fail("����ȡ�µ�ǰ�ɾͳƺ��ټ��\n"); 	      
                me->set("chenjch",HIC"[��ʥ]"NOR);
            write(HIR"����ɾͳƺųɹ���\n");
        }
        if (arg == "����")
        {        
                if (!me->query("titles/����"))
                    return notify_fail("�㻹δ�������ɾͳƺš�\n"); 
				if(me->query("chenjch"))
				    return notify_fail("����ȡ�µ�ǰ�ɾͳƺ��ټ��\n"); 	      
                me->set("chenjch",HIC"[����]"NOR);
            write(HIR"����ɾͳƺųɹ���\n");
        }
        if (arg == "����")
        {        
                if (!me->query("titles/����"))
                    return notify_fail("�㻹δ�������ɾͳƺš�\n"); 
				if(me->query("chenjch"))
				    return notify_fail("����ȡ�µ�ǰ�ɾͳƺ��ټ��\n"); 	      
                me->set("chenjch",HIC"[����]"NOR);
            write(HIR"����ɾͳƺųɹ���\n");
        }
        if (arg == "����")
        {        
                if (!me->query("titles/����"))
                    return notify_fail("�㻹δ�������ɾͳƺš�\n"); 
				if(me->query("chenjch"))
				    return notify_fail("����ȡ�µ�ǰ�ɾͳƺ��ټ��\n"); 	      
                me->set("chenjch",HIC"[����]"NOR);
            write(HIR"����ɾͳƺųɹ���\n");
        }
        if (arg == "��ڤ��")
        {        
                if (!me->query("titles/��ڤ��"))
                    return notify_fail("�㻹δ�������ɾͳƺš�\n"); 
				if(me->query("chenjch"))
				    return notify_fail("����ȡ�µ�ǰ�ɾͳƺ��ټ��\n"); 	      
                me->set("chenjch",HIC"[��ڤ��]"NOR);
            write(HIR"����ɾͳƺųɹ���\n");
        }
        if (arg == "��Ľ��")
        {        
                if (!me->query("titles/��Ľ��"))
                    return notify_fail("�㻹δ�������ɾͳƺš�\n"); 
				if(me->query("chenjch"))
				    return notify_fail("����ȡ�µ�ǰ�ɾͳƺ��ټ��\n"); 	      
                me->set("chenjch",HIC"[��Ľ��]"NOR);
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
        if (arg == "��ҹ����")
        {        
                if (!me->query("titles/��ҹ����"))
                    return notify_fail("�㻹δ�������ɾͳƺš�\n"); 
				if(me->query("chenjch"))
				    return notify_fail("����ȡ�µ�ǰ�ɾͳƺ��ټ��\n"); 	      
                me->set("chenjch",HIC"[��ҹ����]"NOR);
            write(HIR"����ɾͳƺųɹ���\n");
        }
        if (arg == "�̺�����")
        {        
                if (!me->query("titles/�̺�����"))
                    return notify_fail("�㻹δ�������ɾͳƺš�\n"); 
				if(me->query("chenjch"))
				    return notify_fail("����ȡ�µ�ǰ�ɾͳƺ��ټ��\n"); 	      
                me->set("chenjch",HIC"[�̺�����]"NOR);
            write(HIR"����ɾͳƺųɹ���\n");
        }
        if (arg == "����֮��")
        {        
                if (!me->query("titles/����֮��"))
                    return notify_fail("�㻹δ�������ɾͳƺš�\n"); 
				if(me->query("chenjch"))
				    return notify_fail("����ȡ�µ�ǰ�ɾͳƺ��ټ��\n"); 	      
                me->set("chenjch",HIC"[����֮��]"NOR);
            write(HIR"����ɾͳƺųɹ���\n");
        }
        if (arg == "ѩ�Ϸɺ�")
        {        
                if (!me->query("titles/ѩ�Ϸɺ�"))
                    return notify_fail("�㻹δ�������ɾͳƺš�\n"); 
				if(me->query("chenjch"))
				    return notify_fail("����ȡ�µ�ǰ�ɾͳƺ��ټ��\n"); 	      
                me->set("chenjch",HIC"[ѩ�Ϸɺ�]"NOR);
            write(HIR"����ɾͳƺųɹ���\n");
        }
        if (arg == "��Ӱ����")
        {        
                if (!me->query("titles/��Ӱ����"))
                    return notify_fail("�㻹δ�������ɾͳƺš�\n"); 
				if(me->query("chenjch"))
				    return notify_fail("����ȡ�µ�ǰ�ɾͳƺ��ټ��\n"); 	      
                me->set("chenjch",HIC"[��Ӱ����]"NOR);
            write(HIR"����ɾͳƺųɹ���\n");
        }
		if (arg == "���ɵй�")
        {        
                if (!me->query("titles/���ɵй�"))
                    return notify_fail("�㻹δ�������ɾͳƺš�\n"); 
				if(me->query("chenjch"))
				    return notify_fail("����ȡ�µ�ǰ�ɾͳƺ��ټ��\n"); 	      
                me->set("chenjch",HIC"[���ɵй�]"NOR);
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
		if (arg == "İ�Ͼ���")
        {        
                if (!me->query("titles/İ�Ͼ���"))
                    return notify_fail("�㻹δ�������ɾͳƺš�\n"); 
				if(me->query("chenjch"))
				    return notify_fail("����ȡ�µ�ǰ�ɾͳƺ��ټ��\n"); 	      
                me->set("chenjch",HIC"[İ�Ͼ���]"NOR);
            write(HIR"����ɾͳƺųɹ���\n");
        }
		if (arg == "��������")
        {        
                if (!me->query("titles/��������"))
                    return notify_fail("�㻹δ�������ɾͳƺš�\n"); 
				if(me->query("chenjch"))
				    return notify_fail("����ȡ�µ�ǰ�ɾͳƺ��ټ��\n"); 	      
                me->set("chenjch",HIC"[��������]"NOR);
            write(HIR"����ɾͳƺųɹ���\n");
        }
		if (arg == "��������")
        {        
                if (!me->query("titles/��������"))
                    return notify_fail("�㻹δ�������ɾͳƺš�\n"); 
				if(me->query("chenjch"))
				    return notify_fail("����ȡ�µ�ǰ�ɾͳƺ��ټ��\n"); 	      
                me->set("chenjch",HIC"[��������]"NOR);
            write(HIR"����ɾͳƺųɹ���\n");
        }
        if (arg == "һ������")
        {        
                if (!me->query("titles/һ������"))
                    return notify_fail("�㻹δ�������ɾͳƺš�\n"); 
				if(me->query("chenjch"))
				    return notify_fail("����ȡ�µ�ǰ�ɾͳƺ��ټ��\n"); 	      
                me->set("chenjch",HIC"[����]"NOR);
            write(HIR"����ɾͳƺųɹ���\n");
        }

         if (arg == "slr")
        {
                        
                if (!me->query("chenghao/slr"))
                    return notify_fail("�㻹δ�������ƺš�\n"); 
					
				if(me->query("chjh"))
				    return notify_fail("����ȡ�µ�ǰ�ƺ��ټ��\n"); 	    
                    
                me->add("chjh",1);
		    	me->add("chjl/bi",10);
		    	me->add("chjl/gen",10);
		    	me->add("chjl/wu",10);
		    	me->add("chjl/shen",10);
		    	me->add("chjl/qi",2000);
		    	me->add("chjl/nei",2000);
		    	me->add("chjl/jing",2000);
		    	me->set("title",HIY"������"NOR);
                 
			
            write(HIR"����ƺųɹ���\n");
        }
        if (arg == "xsxx")
        {
                        
                if (!me->query("chenghao/xsxx"))
                    return notify_fail("�㻹δ�������ƺš�\n"); 
					
				if(me->query("chjh"))
				    return notify_fail("����ȡ�µ�ǰ�ƺ��ټ��\n");	    
                    
                me->add("chjh",1);
		    	me->add("chjl/bi",5);
		    	me->add("chjl/shen",5);
		    	me->set("title",HIG"����С��"NOR);
                 
			
            write(HIR"����ƺųɹ���\n");
        }
        if (arg == "yddx")
        {
                        
                if (!me->query("chenghao/yddx"))
                    return notify_fail("�㻹δ�������ƺš�\n"); 
					
				if(me->query("chjh"))
				    return notify_fail("����ȡ�µ�ǰ�ƺ��ټ��\n");	    
                    
                me->add("chjh",1);
		    	me->add("chjl/bi",5);
		    	me->add("chjl/gen",5);
		    	me->add("chjl/wu",5);
		    	me->add("chjl/shen",5);
		    	me->set("title",HIB"һ������"NOR);
                 
			
            write(HIR"����ƺųɹ���\n");
        }
		if (arg == "jq")
        {
                        
                if (!me->query("jq"))
                    return notify_fail("�㻹δ�������ƺš�\n"); 
					
				if(me->query("chjh"))
				    return notify_fail("����ȡ�µ�ǰ�ƺ��ټ��\n");	    
                    
                me->add("chjh",1);
		    	me->add("titlea/str",66);
		    	me->add("titlea/int",66);
		    	me->add("titlea/dex",66);
		    	me->add("titlea/con",66);
		    	me->set("title",HBRED"����"HBBLU"ҹ��"NOR);
                 
			
            write(HIR"����ƺųɹ���\n");
        }
		if (arg == "lx")
        {
                        
                if (!me->query("lx"))
                    return notify_fail("�㻹δ�������ƺš�\n"); 
					
				if(me->query("chjh"))
				    return notify_fail("����ȡ�µ�ǰ�ƺ��ټ��\n");	    
                    
                me->add("chjh",1);
		    	me->add("titlea/str",40);
		    	me->add("titlea/int",40);
		    	me->add("titlea/dex",40);
		    	me->add("titlea/con",40);
		    	me->set("title",HIR" �� �� "NOR);
                 
			
            write(HIR"����ƺųɹ���\n");
        }
		if (arg == "yj")
        {
                        
                if (!me->query("yj"))
                    return notify_fail("�㻹δ�������ƺš�\n"); 
					
				if(me->query("chjh"))
				    return notify_fail("����ȡ�µ�ǰ�ƺ��ټ��\n");	    
                    
                me->add("chjh",1);
		    	me->add("titlea/str",80);
		    	me->add("titlea/int",80);
		    	me->add("titlea/dex",80);
		    	me->add("titlea/con",80);
		    	me->set("title",HBMAG"��������"NOR);
                 
			
            write(HIR"����ƺųɹ���\n");
        }
        if (arg == "jhyl")
        {
                        
                if (!me->query("chenghao/jhyl"))
                    return notify_fail("�㻹δ�������ƺš�\n"); 
					
				if(me->query("chjh"))
				    return notify_fail("����ȡ�µ�ǰ�ƺ��ټ��\n");	    
                    
                me->add("chjh",1);
		    	me->add("chjl/bi",5);
		    	me->add("chjl/gen",5);
		    	me->add("chjl/wu",5);
		    	me->add("chjl/shen",5);
		    	me->add("chjl/qi",500);
		    	me->add("chjl/nei",500);
		    	me->add("chjl/jing",500);
		    	me->set("title",HIB"����Ԫ��"NOR);
                 
			
            write(HIR"����ƺųɹ���\n");
        }
        if (arg == "lyxz")
        {
                        
                if (!me->query("chenghao/lyxz"))
                    return notify_fail("�㻹δ�������ƺš�\n"); 
					
				if(me->query("chjh"))
				    return notify_fail("����ȡ�µ�ǰ�ƺ��ټ��\n");	    
                    
                me->add("chjh",1);
		    	me->add("chjl/bi",10);
		    	me->add("chjl/gen",10);
		    	me->add("chjl/wu",10);
		    	me->add("chjl/shen",10);
		    	me->add("chjl/qi",500);
		    	me->add("chjl/nei",500);
		    	me->add("chjl/jing",500);
		    	me->set("title",HIY"��Ұ����"NOR);
                 
			
            write(HIR"����ƺųɹ���\n");
        }
        if (arg == "kwxf")
        {
                        
                if (!me->query("chenghao/kwxf"))
                    return notify_fail("�㻹δ�������ƺš�\n"); 
					
				if(me->query("chjh"))
				    return notify_fail("����ȡ�µ�ǰ�ƺ��ټ��\n");	    
                    
                me->add("chjh",1);
		    	me->add("chjl/bi",10);
		    	me->add("chjl/gen",10);
		    	me->add("chjl/wu",10);
		    	me->add("chjl/shen",10);
		    	me->add("chjl/qi",500);
		    	me->add("chjl/nei",500);
		    	me->add("chjl/jing",500);
		    	me->set("title",HIY"�����ȷ�"NOR);
                 
			
            write(HIR"����ƺųɹ���\n");
        }
        if (arg == "hydt")
        {
                        
                if (!me->query("chenghao/hydt"))
                    return notify_fail("�㻹δ�������ƺš�\n"); 
					
				if(me->query("chjh"))
				    return notify_fail("����ȡ�µ�ǰ�ƺ��ټ��\n");	    
                    
                me->add("chjh",1);
		    	me->add("chjl/fu",10);
		    	me->set("title",HIR"���˵�ͷ"NOR);
                 
			
            write(HIR"����ƺųɹ���\n");
        }
        if (arg == "zwhy")
        {
                        
                if (!me->query("chenghao/zwhy"))
                    return notify_fail("�㻹δ�������ƺš�\n"); 
					
				if(me->query("chjh"))
				    return notify_fail("����ȡ�µ�ǰ�ƺ��ټ��\n");	    
                    
                me->add("chjh",1);
		    	me->add("chjl/bi",5);
		    	me->add("chjl/gen",5);
		    	me->add("chjl/wu",5);
		    	me->add("chjl/shen",5);	
		    	me->set("title",HIW"���Ի���"NOR);
                			
            write(HIR"����ƺųɹ���\n");
        }
        if (arg == "fltt")
        {
                        
                if (!me->query("chenghao/fltt"))
                    return notify_fail("�㻹δ�������ƺš�\n"); 
					
				if(me->query("chjh"))
				    return notify_fail("����ȡ�µ�ǰ�ƺ��ټ��\n");	    
                    
                me->add("chjh",1);
		    	me->add("chjl/bi",5);
		    	me->add("chjl/gen",5);
		    	me->add("chjl/wu",5);
		    	me->add("chjl/shen",5);	
		    	me->set("title",HIW"��������"NOR);
                 			
            write(HIR"����ƺųɹ���\n");
        }
        if (arg == "hxtx")
        {
                        
                if (!me->query("chenghao/hxtx"))
                    return notify_fail("�㻹δ�������ƺš�\n"); 
					
				if(me->query("chjh"))
				    return notify_fail("����ȡ�µ�ǰ�ƺ��ټ��\n");	    
                    
                me->add("chjh",1);
		    	me->add("chjl/bi",10);
		    	me->add("chjl/gen",10);
		    	me->add("chjl/wu",10);
		    	me->add("chjl/shen",10);	
		    	me->set("title",HIW"��������"NOR);
                			
            write(HIR"����ƺųɹ���\n");
        }
        if (arg == "yxqc")
        {
                        
                if (!me->query("chenghao/yxqc"))
                    return notify_fail("�㻹δ�������ƺš�\n"); 
					
				if(me->query("chjh"))
				    return notify_fail("����ȡ�µ�ǰ�ƺ��ټ��\n");	    
                    
                me->add("chjh",1);
		    	me->add("chjl/bi",10);
		    	me->add("chjl/gen",10);
		    	me->add("chjl/wu",10);
		    	me->add("chjl/shen",10);	
		    	me->set("title",HIW"һЦ���"NOR);
                 			
            write(HIR"����ƺųɹ���\n");
        }
        if (arg == "qsyr")
        {
                        
                if (!me->query("chenghao/qsyr"))
                    return notify_fail("�㻹δ�������ƺš�\n"); 
					
				if(me->query("chjh"))
				    return notify_fail("����ȡ�µ�ǰ�ƺ��ټ��\n");	    
                    
                me->add("chjh",1);
		    	me->add("chjl/bi",10);
		    	me->add("chjl/gen",10);
		    	me->add("chjl/wu",10);
		    	me->add("chjl/shen",10);
				me->add("chjl/qi",1000);
		    	me->add("chjl/nei",1000);
		    	me->add("chjl/jing",1000);	
		    	me->set("title",HIW"��ˮ����"NOR);
                			
            write(HIR"����ƺųɹ���\n");
        }
        if (arg == "mspa")
        {
                        
                if (!me->query("chenghao/mspa"))
                    return notify_fail("�㻹δ�������ƺš�\n"); 
					
				if(me->query("chjh"))
				    return notify_fail("����ȡ�µ�ǰ�ƺ��ټ��\n");	    
                    
                me->add("chjh",1);
		    	me->add("chjl/bi",10);
		    	me->add("chjl/gen",10);
		    	me->add("chjl/wu",10);
		    	me->add("chjl/shen",10);
				me->add("chjl/qi",1000);
		    	me->add("chjl/nei",1000);
		    	me->add("chjl/jing",1000);	
		    	me->set("title",HIW"òʤ�˰�"NOR);
                 			
            write(HIR"����ƺųɹ���\n");
        }
        if (arg == "ljty")
        {
                        
                if (!me->query("chenghao/ljty"))
                    return notify_fail("�㻹δ�������ƺš�\n"); 
					
				if(me->query("chjh"))
				    return notify_fail("����ȡ�µ�ǰ�ƺ��ټ��\n");	    
                    
                me->add("chjh",1);
		    	me->add("chjl/bi",5);
		    	me->add("chjl/gen",5);
		    	me->add("chjl/wu",5);
		    	me->add("chjl/shen",5);
				me->add("chjl/qi",500);
		    	me->add("chjl/nei",500);
		    	me->add("chjl/jing",500);	
		    	me->add("chjl/exp",10);
		    	me->set("title",HIY"�˼�����"NOR);
                			
            write(HIR"����ƺųɹ���\n");
        }
        if (arg == "zmjh")
        {
                        
                if (!me->query("chenghao/zmjh"))
                    return notify_fail("�㻹δ�������ƺš�\n"); 
					
				if(me->query("chjh"))
				    return notify_fail("����ȡ�µ�ǰ�ƺ��ټ��\n");	    
                    
                me->add("chjh",1);
		    	me->add("chjl/bi",5);
		    	me->add("chjl/gen",5);
		    	me->add("chjl/wu",5);
		    	me->add("chjl/shen",5);
				me->add("chjl/qi",500);
		    	me->add("chjl/nei",500);
		    	me->add("chjl/jing",500);	
		    	me->add("chjl/exp",10);
		    	me->set("title",HIM"������"NOR);
                			
            write(HIR"����ƺųɹ���\n");
        } 

        return 1;
}


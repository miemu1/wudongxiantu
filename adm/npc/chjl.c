
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	    object ob1;
        int min, hrs, day, mon, age;
        me=this_player();
        
        if (! arg || arg == "")
                return notify_fail("你要激活什么称号！\n");
                         
        if (me->is_fighting())
                return notify_fail("你正忙着打架呢，哪有时间做这种事？\n");

        if (me->is_busy())
                return notify_fail("你正忙，没法静下心来。\n");
                					
					
		if (arg == "quxiao")
        {
                        
                
                me->delete("chjh");
		    	me->delete("chjl");
		    	me->delete("title");
                me->delete("chenghao");
			    me->delete("titlea");
            write(HIR"取下前缀称号成功，你可以激活其他称号了。\n");
        }			 
		if (arg == "quxiao1")
        {
                        
                
                me->delete("chenjch");
//		    	me->delete("chjl");
//		    	me->delete("title");
//               me->delete("chenghao");
			
            write(HIR"取下成就称号成功，你可以激活其他成就称号了。\n");
        }	
		
         if (arg == "初入武道")
        {        
                if (!me->query("titles/初入武道"))
                    return notify_fail("你还未获得这项成就称号。\n"); 
				if(me->query("chenjch"))
				    return notify_fail("请先取下当前成就称号再激活。\n"); 	      
                me->set("chenjch",HIC"[初入武道]"NOR);
            write(HIR"激活成就称号成功。\n");
        }
         if (arg == "绝仙之毒")
        {        
                if (!me->query("titles/绝仙之毒"))
                    return notify_fail("你还未获得这项成就称号。\n"); 
				if(me->query("chenjch"))
				    return notify_fail("请先取下当前成就称号再激活。\n"); 	      
                me->set("chenjch",HIC"[初入武道]"NOR);
            write(HIR"激活成就称号成功。\n");
        }
         if (arg == "老魔修剑")
        {        
                if (!me->query("titles/老魔修剑"))
                    return notify_fail("你还未获得这项成就称号。\n"); 
				if(me->query("chenjch"))
				    return notify_fail("请先取下当前成就称号再激活。\n"); 	      
                me->set("chenjch",HIC"[老魔修剑]"NOR);
            write(HIR"激活成就称号成功。\n");
        }
         if (arg == "太极真人")
        {        
                if (!me->query("titles/太极真人"))
                    return notify_fail("你还未获得这项成就称号。\n"); 
				if(me->query("chenjch"))
				    return notify_fail("请先取下当前成就称号再激活。\n"); 	      
                me->set("chenjch",HIC"[太极真人]"NOR);
            write(HIR"激活成就称号成功。\n");
        }
        if (arg == "阳圣")
        {        
                if (!me->query("titles/阳圣"))
                    return notify_fail("你还未获得这项成就称号。\n"); 
				if(me->query("chenjch"))
				    return notify_fail("请先取下当前成就称号再激活。\n"); 	      
                me->set("chenjch",HIC"[阳圣]"NOR);
            write(HIR"激活成就称号成功。\n");
        }
        if (arg == "金身")
        {        
                if (!me->query("titles/金身"))
                    return notify_fail("你还未获得这项成就称号。\n"); 
				if(me->query("chenjch"))
				    return notify_fail("请先取下当前成就称号再激活。\n"); 	      
                me->set("chenjch",HIC"[金身]"NOR);
            write(HIR"激活成就称号成功。\n");
        }
        if (arg == "佳人")
        {        
                if (!me->query("titles/佳人"))
                    return notify_fail("你还未获得这项成就称号。\n"); 
				if(me->query("chenjch"))
				    return notify_fail("请先取下当前成就称号再激活。\n"); 	      
                me->set("chenjch",HIC"[佳人]"NOR);
            write(HIR"激活成就称号成功。\n");
        }
        if (arg == "君子")
        {        
                if (!me->query("titles/君子"))
                    return notify_fail("你还未获得这项成就称号。\n"); 
				if(me->query("chenjch"))
				    return notify_fail("请先取下当前成就称号再激活。\n"); 	      
                me->set("chenjch",HIC"[君子]"NOR);
            write(HIR"激活成就称号成功。\n");
        }
        if (arg == "北冥潇")
        {        
                if (!me->query("titles/北冥潇"))
                    return notify_fail("你还未获得这项成就称号。\n"); 
				if(me->query("chenjch"))
				    return notify_fail("请先取下当前成就称号再激活。\n"); 	      
                me->set("chenjch",HIC"[北冥潇]"NOR);
            write(HIR"激活成就称号成功。\n");
        }
        if (arg == "南慕容")
        {        
                if (!me->query("titles/南慕容"))
                    return notify_fail("你还未获得这项成就称号。\n"); 
				if(me->query("chenjch"))
				    return notify_fail("请先取下当前成就称号再激活。\n"); 	      
                me->set("chenjch",HIC"[南慕容]"NOR);
            write(HIR"激活成就称号成功。\n");
        }
        if (arg == "侠客行")
        {        
                if (!me->query("titles/侠客行"))
                    return notify_fail("你还未获得这项成就称号。\n"); 
				if(me->query("chenjch"))
				    return notify_fail("请先取下当前成就称号再激活。\n"); 	      
                me->set("chenjch",HIC"[侠客行]"NOR);
            write(HIR"激活成就称号成功。\n");
        }
        if (arg == "暗夜鬼魅")
        {        
                if (!me->query("titles/暗夜鬼魅"))
                    return notify_fail("你还未获得这项成就称号。\n"); 
				if(me->query("chenjch"))
				    return notify_fail("请先取下当前成就称号再激活。\n"); 	      
                me->set("chenjch",HIC"[暗夜鬼魅]"NOR);
            write(HIR"激活成就称号成功。\n");
        }
        if (arg == "碧海潮生")
        {        
                if (!me->query("titles/碧海潮生"))
                    return notify_fail("你还未获得这项成就称号。\n"); 
				if(me->query("chenjch"))
				    return notify_fail("请先取下当前成就称号再激活。\n"); 	      
                me->set("chenjch",HIC"[碧海潮生]"NOR);
            write(HIR"激活成就称号成功。\n");
        }
        if (arg == "龙象之力")
        {        
                if (!me->query("titles/龙象之力"))
                    return notify_fail("你还未获得这项成就称号。\n"); 
				if(me->query("chenjch"))
				    return notify_fail("请先取下当前成就称号再激活。\n"); 	      
                me->set("chenjch",HIC"[龙象之力]"NOR);
            write(HIR"激活成就称号成功。\n");
        }
        if (arg == "雪上飞狐")
        {        
                if (!me->query("titles/雪上飞狐"))
                    return notify_fail("你还未获得这项成就称号。\n"); 
				if(me->query("chenjch"))
				    return notify_fail("请先取下当前成就称号再激活。\n"); 	      
                me->set("chenjch",HIC"[雪上飞狐]"NOR);
            write(HIR"激活成就称号成功。\n");
        }
        if (arg == "如影随形")
        {        
                if (!me->query("titles/如影随形"))
                    return notify_fail("你还未获得这项成就称号。\n"); 
				if(me->query("chenjch"))
				    return notify_fail("请先取下当前成就称号再激活。\n"); 	      
                me->set("chenjch",HIC"[如影随形]"NOR);
            write(HIR"激活成就称号成功。\n");
        }
		if (arg == "富可敌国")
        {        
                if (!me->query("titles/富可敌国"))
                    return notify_fail("你还未获得这项成就称号。\n"); 
				if(me->query("chenjch"))
				    return notify_fail("请先取下当前成就称号再激活。\n"); 	      
                me->set("chenjch",HIC"[富可敌国]"NOR);
            write(HIR"激活成就称号成功。\n");
        }
		if (arg == "倾国倾城")
        {        
                if (!me->query("titles/倾国倾城"))
                    return notify_fail("你还未获得这项成就称号。\n"); 
				if(me->query("chenjch"))
				    return notify_fail("请先取下当前成就称号再激活。\n"); 	      
                me->set("chenjch",HIC"[倾国倾城]"NOR);
            write(HIR"激活成就称号成功。\n");
        }
		if (arg == "陌上君子")
        {        
                if (!me->query("titles/陌上君子"))
                    return notify_fail("你还未获得这项成就称号。\n"); 
				if(me->query("chenjch"))
				    return notify_fail("请先取下当前成就称号再激活。\n"); 	      
                me->set("chenjch",HIC"[陌上君子]"NOR);
            write(HIR"激活成就称号成功。\n");
        }
		if (arg == "独步江湖")
        {        
                if (!me->query("titles/独步江湖"))
                    return notify_fail("你还未获得这项成就称号。\n"); 
				if(me->query("chenjch"))
				    return notify_fail("请先取下当前成就称号再激活。\n"); 	      
                me->set("chenjch",HIC"[独步江湖]"NOR);
            write(HIR"激活成就称号成功。\n");
        }
		if (arg == "百岁老人")
        {        
                if (!me->query("titles/百岁老人"))
                    return notify_fail("你还未获得这项成就称号。\n"); 
				if(me->query("chenjch"))
				    return notify_fail("请先取下当前成就称号再激活。\n"); 	      
                me->set("chenjch",HIC"[百岁老人]"NOR);
            write(HIR"激活成就称号成功。\n");
        }
        if (arg == "一剑西来")
        {        
                if (!me->query("titles/一剑西来"))
                    return notify_fail("你还未获得这项成就称号。\n"); 
				if(me->query("chenjch"))
				    return notify_fail("请先取下当前成就称号再激活。\n"); 	      
                me->set("chenjch",HIC"[剑仙]"NOR);
            write(HIR"激活成就称号成功。\n");
        }

         if (arg == "slr")
        {
                        
                if (!me->query("chenghao/slr"))
                    return notify_fail("你还未获得这项称号。\n"); 
					
				if(me->query("chjh"))
				    return notify_fail("请先取下当前称号再激活。\n"); 	    
                    
                me->add("chjh",1);
		    	me->add("chjl/bi",10);
		    	me->add("chjl/gen",10);
		    	me->add("chjl/wu",10);
		    	me->add("chjl/shen",10);
		    	me->add("chjl/qi",2000);
		    	me->add("chjl/nei",2000);
		    	me->add("chjl/jing",2000);
		    	me->set("title",HIY"守陵人"NOR);
                 
			
            write(HIR"激活称号成功。\n");
        }
        if (arg == "xsxx")
        {
                        
                if (!me->query("chenghao/xsxx"))
                    return notify_fail("你还未获得这项称号。\n"); 
					
				if(me->query("chjh"))
				    return notify_fail("请先取下当前称号再激活。\n");	    
                    
                me->add("chjh",1);
		    	me->add("chjl/bi",5);
		    	me->add("chjl/shen",5);
		    	me->set("title",HIG"潇洒小侠"NOR);
                 
			
            write(HIR"激活称号成功。\n");
        }
        if (arg == "yddx")
        {
                        
                if (!me->query("chenghao/yddx"))
                    return notify_fail("你还未获得这项称号。\n"); 
					
				if(me->query("chjh"))
				    return notify_fail("请先取下当前称号再激活。\n");	    
                    
                me->add("chjh",1);
		    	me->add("chjl/bi",5);
		    	me->add("chjl/gen",5);
		    	me->add("chjl/wu",5);
		    	me->add("chjl/shen",5);
		    	me->set("title",HIB"一代大侠"NOR);
                 
			
            write(HIR"激活称号成功。\n");
        }
		if (arg == "jq")
        {
                        
                if (!me->query("jq"))
                    return notify_fail("你还未获得这项称号。\n"); 
					
				if(me->query("chjh"))
				    return notify_fail("请先取下当前称号再激活。\n");	    
                    
                me->add("chjh",1);
		    	me->add("titlea/str",66);
		    	me->add("titlea/int",66);
		    	me->add("titlea/dex",66);
		    	me->add("titlea/con",66);
		    	me->set("title",HBRED"潇湘"HBBLU"夜雨"NOR);
                 
			
            write(HIR"激活称号成功。\n");
        }
		if (arg == "lx")
        {
                        
                if (!me->query("lx"))
                    return notify_fail("你还未获得这项称号。\n"); 
					
				if(me->query("chjh"))
				    return notify_fail("请先取下当前称号再激活。\n");	    
                    
                me->add("chjh",1);
		    	me->add("titlea/str",40);
		    	me->add("titlea/int",40);
		    	me->add("titlea/dex",40);
		    	me->add("titlea/con",40);
		    	me->set("title",HIR" 神 行 "NOR);
                 
			
            write(HIR"激活称号成功。\n");
        }
		if (arg == "yj")
        {
                        
                if (!me->query("yj"))
                    return notify_fail("你还未获得这项称号。\n"); 
					
				if(me->query("chjh"))
				    return notify_fail("请先取下当前称号再激活。\n");	    
                    
                me->add("chjh",1);
		    	me->add("titlea/str",80);
		    	me->add("titlea/int",80);
		    	me->add("titlea/dex",80);
		    	me->add("titlea/con",80);
		    	me->set("title",HBMAG"风流倜傥"NOR);
                 
			
            write(HIR"激活称号成功。\n");
        }
        if (arg == "jhyl")
        {
                        
                if (!me->query("chenghao/jhyl"))
                    return notify_fail("你还未获得这项称号。\n"); 
					
				if(me->query("chjh"))
				    return notify_fail("请先取下当前称号再激活。\n");	    
                    
                me->add("chjh",1);
		    	me->add("chjl/bi",5);
		    	me->add("chjl/gen",5);
		    	me->add("chjl/wu",5);
		    	me->add("chjl/shen",5);
		    	me->add("chjl/qi",500);
		    	me->add("chjl/nei",500);
		    	me->add("chjl/jing",500);
		    	me->set("title",HIB"江湖元老"NOR);
                 
			
            write(HIR"激活称号成功。\n");
        }
        if (arg == "lyxz")
        {
                        
                if (!me->query("chenghao/lyxz"))
                    return notify_fail("你还未获得这项称号。\n"); 
					
				if(me->query("chjh"))
				    return notify_fail("请先取下当前称号再激活。\n");	    
                    
                me->add("chjh",1);
		    	me->add("chjl/bi",10);
		    	me->add("chjl/gen",10);
		    	me->add("chjl/wu",10);
		    	me->add("chjl/shen",10);
		    	me->add("chjl/qi",500);
		    	me->add("chjl/nei",500);
		    	me->add("chjl/jing",500);
		    	me->set("title",HIY"绿野仙踪"NOR);
                 
			
            write(HIR"激活称号成功。\n");
        }
        if (arg == "kwxf")
        {
                        
                if (!me->query("chenghao/kwxf"))
                    return notify_fail("你还未获得这项称号。\n"); 
					
				if(me->query("chjh"))
				    return notify_fail("请先取下当前称号再激活。\n");	    
                    
                me->add("chjh",1);
		    	me->add("chjl/bi",10);
		    	me->add("chjl/gen",10);
		    	me->add("chjl/wu",10);
		    	me->add("chjl/shen",10);
		    	me->add("chjl/qi",500);
		    	me->add("chjl/nei",500);
		    	me->add("chjl/jing",500);
		    	me->set("title",HIY"抗倭先锋"NOR);
                 
			
            write(HIR"激活称号成功。\n");
        }
        if (arg == "hydt")
        {
                        
                if (!me->query("chenghao/hydt"))
                    return notify_fail("你还未获得这项称号。\n"); 
					
				if(me->query("chjh"))
				    return notify_fail("请先取下当前称号再激活。\n");	    
                    
                me->add("chjh",1);
		    	me->add("chjl/fu",10);
		    	me->set("title",HIR"鸿运当头"NOR);
                 
			
            write(HIR"激活称号成功。\n");
        }
        if (arg == "zwhy")
        {
                        
                if (!me->query("chenghao/zwhy"))
                    return notify_fail("你还未获得这项称号。\n"); 
					
				if(me->query("chjh"))
				    return notify_fail("请先取下当前称号再激活。\n");	    
                    
                me->add("chjh",1);
		    	me->add("chjl/bi",5);
		    	me->add("chjl/gen",5);
		    	me->add("chjl/wu",5);
		    	me->add("chjl/shen",5);	
		    	me->set("title",HIW"醉卧花荫"NOR);
                			
            write(HIR"激活称号成功。\n");
        }
        if (arg == "fltt")
        {
                        
                if (!me->query("chenghao/fltt"))
                    return notify_fail("你还未获得这项称号。\n"); 
					
				if(me->query("chjh"))
				    return notify_fail("请先取下当前称号再激活。\n");	    
                    
                me->add("chjh",1);
		    	me->add("chjl/bi",5);
		    	me->add("chjl/gen",5);
		    	me->add("chjl/wu",5);
		    	me->add("chjl/shen",5);	
		    	me->set("title",HIW"风流倜傥"NOR);
                 			
            write(HIR"激活称号成功。\n");
        }
        if (arg == "hxtx")
        {
                        
                if (!me->query("chenghao/hxtx"))
                    return notify_fail("你还未获得这项称号。\n"); 
					
				if(me->query("chjh"))
				    return notify_fail("请先取下当前称号再激活。\n");	    
                    
                me->add("chjh",1);
		    	me->add("chjl/bi",10);
		    	me->add("chjl/gen",10);
		    	me->add("chjl/wu",10);
		    	me->add("chjl/shen",10);	
		    	me->set("title",HIW"红袖添香"NOR);
                			
            write(HIR"激活称号成功。\n");
        }
        if (arg == "yxqc")
        {
                        
                if (!me->query("chenghao/yxqc"))
                    return notify_fail("你还未获得这项称号。\n"); 
					
				if(me->query("chjh"))
				    return notify_fail("请先取下当前称号再激活。\n");	    
                    
                me->add("chjh",1);
		    	me->add("chjl/bi",10);
		    	me->add("chjl/gen",10);
		    	me->add("chjl/wu",10);
		    	me->add("chjl/shen",10);	
		    	me->set("title",HIW"一笑倾城"NOR);
                 			
            write(HIR"激活称号成功。\n");
        }
        if (arg == "qsyr")
        {
                        
                if (!me->query("chenghao/qsyr"))
                    return notify_fail("你还未获得这项称号。\n"); 
					
				if(me->query("chjh"))
				    return notify_fail("请先取下当前称号再激活。\n");	    
                    
                me->add("chjh",1);
		    	me->add("chjl/bi",10);
		    	me->add("chjl/gen",10);
		    	me->add("chjl/wu",10);
		    	me->add("chjl/shen",10);
				me->add("chjl/qi",1000);
		    	me->add("chjl/nei",1000);
		    	me->add("chjl/jing",1000);	
		    	me->set("title",HIW"秋水伊人"NOR);
                			
            write(HIR"激活称号成功。\n");
        }
        if (arg == "mspa")
        {
                        
                if (!me->query("chenghao/mspa"))
                    return notify_fail("你还未获得这项称号。\n"); 
					
				if(me->query("chjh"))
				    return notify_fail("请先取下当前称号再激活。\n");	    
                    
                me->add("chjh",1);
		    	me->add("chjl/bi",10);
		    	me->add("chjl/gen",10);
		    	me->add("chjl/wu",10);
		    	me->add("chjl/shen",10);
				me->add("chjl/qi",1000);
		    	me->add("chjl/nei",1000);
		    	me->add("chjl/jing",1000);	
		    	me->set("title",HIW"貌胜潘安"NOR);
                 			
            write(HIR"激活称号成功。\n");
        }
        if (arg == "ljty")
        {
                        
                if (!me->query("chenghao/ljty"))
                    return notify_fail("你还未获得这项称号。\n"); 
					
				if(me->query("chjh"))
				    return notify_fail("请先取下当前称号再激活。\n");	    
                    
                me->add("chjh",1);
		    	me->add("chjl/bi",5);
		    	me->add("chjl/gen",5);
		    	me->add("chjl/wu",5);
		    	me->add("chjl/shen",5);
				me->add("chjl/qi",500);
		    	me->add("chjl/nei",500);
		    	me->add("chjl/jing",500);	
		    	me->add("chjl/exp",10);
		    	me->set("title",HIY"浪迹天涯"NOR);
                			
            write(HIR"激活称号成功。\n");
        }
        if (arg == "zmjh")
        {
                        
                if (!me->query("chenghao/zmjh"))
                    return notify_fail("你还未获得这项称号。\n"); 
					
				if(me->query("chjh"))
				    return notify_fail("请先取下当前称号再激活。\n");	    
                    
                me->add("chjh",1);
		    	me->add("chjl/bi",5);
		    	me->add("chjl/gen",5);
		    	me->add("chjl/wu",5);
		    	me->add("chjl/shen",5);
				me->add("chjl/qi",500);
		    	me->add("chjl/nei",500);
		    	me->add("chjl/jing",500);	
		    	me->add("chjl/exp",10);
		    	me->set("title",HIM"纵马江湖"NOR);
                			
            write(HIR"激活称号成功。\n");
        } 

        return 1;
}


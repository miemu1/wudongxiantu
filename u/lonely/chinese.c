// This program is a part of NITAN MudLIB
// chan_cler �й���ս�� 
   
inherit NPC; 

private void from_wudang();
private void from_shaolin();
private void from_huashan();
private void from_ouyang();
private void from_gaibang();
private void from_taohua();
private void from_emei();
private void from_lingjiu();
private void from_gumu();
private void from_quanzhen();
private void from_mingjiao();
private void from_xingxiu();
private void from_xueshan();
private void from_xuedao();
private void from_xiaoyao();
private void from_shenlong();
private void from_hujia();
private void from_murong();
private void from_duanshi();
private void from_kunlun();
private void from_yaowang();
private void from_wudu();
private void from_lingxiao();
private void from_tiezhang();
private void from_zhenyuan();
private void from_xuanming();
//private void from_mojiao();
//private void from_tangmen();
//private void from_riyue();

/*  
function *init_family = ({ (: from_wudang :),   (: from_shaolin :),   (: from_huashan :), 
                           (: from_ouyang :),   (: from_gaibang :),   (: from_taohua :), 
                           (: from_gumu :),     (: from_xingxiu :),   (: from_xueshan :), 
                           (: from_xuedao :),   (: from_xiaoyao :),   (: from_shenlong :), 
                           (: from_emei :),     (: from_quanzhen :),  (: from_mingjiao :), 
                           (: from_lingjiu :),  (: from_murong :),    (: from_duanshi :),
                           (: from_hujia :),                      
                        }); 

void create() 
{ 
        NPC_D->generate_cn_name(this_object()); 
        set("long", "һ���ˡ�\n"); 
        set("gender", "����"); 
        set("age", 20); 
        set("str", 20); 
        set("int", 20); 
        set("con", 20); 
        set("dex", 20); 
        
        // the follow 5 setting has no use       
        set("max_qi", 100); 
        set("max_jing", 100); 
        set("neili", 100); 
        set("max_neili", 100); 
        set("jiali", 100); 
        
        set("combat_exp", 3000000); 
        
        setup(); 
        
        evaluate(init_family[random(sizeof(init_family))]); 
} 
*/

// external functions
public void setup_family(string family);

mapping init_family = ([
        "������"   : (: from_shaolin :),
        "�䵱��"   : (: from_wudang :),
        "ؤ��"     : (: from_gaibang :),
        "��ɽ��"   : (: from_huashan :),
        "ѩɽ��"   : (: from_xueshan :),
        "�һ���"   : (: from_taohua :),
        "��Ĺ��"   : (: from_gumu :),
        "ȫ���"   : (: from_quanzhen :),
        "������"   : (: from_xingxiu :),
        "������"   : (: from_emei :),
        "Ѫ����"   : (: from_xuedao :),
        "��ң��"   : (: from_xiaoyao :),
        "����"     : (: from_mingjiao :),
        "���չ�"   : (: from_lingjiu :),
        "������"   : (: from_shenlong :),
        "�������" : (: from_hujia :),
        "ŷ������" : (: from_ouyang :),
        "Ľ������" : (: from_murong :),
        "���ϻ���" : (: from_duanshi :),
        "������"   : (: from_kunlun :),
        "ҩ����"   : (: from_yaowang :),
        "�嶾��"   : (: from_wudu :),
        "������"   : (: from_lingxiao :),
        "���ư�"   : (: from_tiezhang :),
        "��ڤ��"   : (: from_xuanming :),
        //"ħ��"     : (: from_mojiao :),
        //"��������" : (: from_tangmen :),
        //"�������" : (: from_riyue :),
]);


varargs void create(string fam)
{
        string *fams;

        NPC_D->generate_cn_name(this_object());
        set("long", "һ���ˡ�\n");
        set("gender", "����");
        set("age", 20);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);

        // the follow 5 setting has no use      
        set("max_qi", 100);
        set("max_jing", 100);
        set("neili", 100);
        set("max_neili", 100);
        set("jiali", 100);

        set("combat_exp", 3000000);

        setup();

        fams = keys(init_family);
        if( fam ) setup_family(fam);
        else setup_family(fams[random(sizeof(fams))]);
}

void setup_family(string family)
{
        function f;
        mapping skills;
        string skill;

//      family = FAMILY_D->query_family_name(family);
        if (! functionp(f = init_family[family]))
                return;

        if (mapp(skills = query_skills()))
        {
                // remove all skill
                foreach (skill in keys(skills))
                        delete_skill(skill);

        }

        // set family information
        /*
        set("family/family_name", family);
        set("family/generation", 0);
        */
        create_family(family, 0, "����"); 

        evaluate(f);
}
        
private void from_wudang()
{
        set("scale", 200);
        set("from", ({
                "��˵���˳����䵱�����䵱�ɵĸ��֣�Ȼ�����䲻�޵£���ϧ����ϧ��",
                "���Ŵ��˱����䵱ɽ��һũ�򣬶���ĿȾ����Ȼ���ͳɷǷ��书��",
                "��˵�������䵱��ͽ�����그��ɱ���������󣬲�����շ�����ԭ��",
        }));

        set_skill("force", 1);
        set_skill("taiji-shengong", 1);
        set_skill("parry", 1);
        set_skill("dodge", 1);
        set_skill("tiyunzong", 1);
        set_skill("sword", 1);
        set_skill("taiji-jian", 1);
        set_skill("cuff", 1);
        set_skill("taiji-quan", 1);
        set_skill("martial-cognize", 1);
        set_skill("taoism", 1);
        set_skill("tianwei-zhengqi", 1);

        map_skill("parry", "taiji-jian");
        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("sword", "taiji-jian");
        map_skill("cuff", "taiji-quan");

        prepare_skill("cuff", "taiji-quan");

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.chan" :),
                (: perform_action, "sword.sui" :),
                (: perform_action, "sword.zhenwu" :),
                (: perform_action, "sword.zhuan" :),
                (: perform_action, "cuff.zhen" :),
                (: perform_action, "cuff.zhan" :),
                (: perform_action, "cuff.ji" :),
                (: perform_action, "cuff.yin" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );

        set("class", "taoist");

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang/obj/greyrobe")->wear();
}
           
private void from_shaolin()
{
        set("scale", 150);
        set("from", ({
                "��˵���˳������֣������ֵ��׼Ҹ��֣���ȴû�а��ȱ�֮�ģ�����",
                "���Ŵ���͵ʦ�����֣�������һ�������׵ı��졣",
                "��˵���������ֵĻ�ͷ�ӣ�͵ѧ���պ󱻷��֣���Ȼ����"
                + "��ĦԺ���ϳ��������벻�����շ�����ԭ��",
                "��˵���˵��그�����ֵĽ��ɣ��������£��벻�����Ӷ���"
                + "�Ժ��Ȼ�س�������"
        }));

        set_skill("force", 1);
        set_skill("hunyuan-yiqi", 1);
        set_skill("parry", 1);
        set_skill("dodge", 1);
        set_skill("shaolin-shenfa", 1);
        set_skill("sword", 1);
        set_skill("damo-jian", 1);
        set_skill("finger", 1);
        set_skill("nianhua-zhi", 1);
        set_skill("strike", 1);
        set_skill("sanhua-zhang", 1);
        set_skill("literate", 1);
        set_skill("martial-cognize", 1);
        set_skill("buddhism", 1);
        set_skill("lunhui", 1);

        map_skill("parry", "damo-jian");
        map_skill("force", "hunyuan-yiqi");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("sword", "damo-jian");
        map_skill("finger", "nianhua-zhi");
        map_skill("strike", "sanhua-zhang");

        prepare_skill("finger", "nianhua-zhi");
        prepare_skill("strike", "sanhua-zhang");

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "sword.sanjue" :),
                (: perform_action, "sword.shang" :),
                (: perform_action, "sword.luan" :),
                (: perform_action, "sword.zhe" :),
                (: perform_action, "strike.san" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );

        set("class", "bonze");

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
}
 
private void from_huashan()
{
        set("scale", 130);
        set("from", ({
                "��˵���˳��Ի�ɽ���޶����������м���Ȼ�������벻�������ֳ�ͷ��",
                "���Ŵ��˱��ǻ�ɽ���ϣ�����֮��ԶͶ��أ���֪�ιʷ�����ԭ��",
                "��˵���˱��Ǳ����Ե׵���ɽȥ�ģ�͵ѧ�����Ժ�û�ر���"
                + "�����ٵؿ��ޣ��������ڵó�������",
        }));

        set_skill("force", 1);
        set_skill("zixia-shengong", 1);
        set_skill("parry", 1);
        set_skill("dodge", 1);
        set_skill("feiyan-huixiang", 1);
        set_skill("sword", 1);
        set_skill("huashan-sword", 1);
        set_skill("cuff", 1);
        set_skill("poyu-quan", 1);
        set_skill("strike", 1);
        set_skill("hunyuan-zhang", 1);
        set_skill("literate", 1);
        set_skill("martial-cognize", 1);
        set_skill("jianyi", 1);
        
        map_skill("parry", "huaxian-sword");
        map_skill("force", "zixia-shengong");
        map_skill("dodge", "feiyan-huixiang");
        map_skill("sword", "huashan-sword");
        map_skill("cuff", "poyu-quan");
        map_skill("strike", "hunyuan-zhang");

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.jie" :),
                (: perform_action, "cuff.lei" :),
                (: perform_action, "cuff.po" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );

        set("class", "fighter");

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

private void from_ouyang() 
{ 
        set("scale", 130); 
        set("from", ({ 
                "��˵����ԭ�ǵ���������ʦŷ������ֳ�����֪�ι�ʧ�٣���" 
                + "�վ�Ȼ�ֳ����ˡ�", 
                "���Ŵ���͵ѧ���������ɽׯŷ�����ҵ��书��������ŷ��" 
                + "�淢�ִ�����ˣ����˴��˶��ߣ���Ȼ����գ�����˼�飡", 
        })); 
        
        set_skill("force", 1); 
        set_skill("hamagong", 1); 
        set_skill("parry", 1); 
        set_skill("dodge", 1); 
        set_skill("chanchu-bufa", 1); 
        set_skill("staff", 1); 
        set_skill("lingshe-zhangfa", 1); 
        set_skill("cuff", 1); 
        set_skill("lingshe-quan", 1); 
        set_skill("finger", 1); 
        set_skill("shedu-qiqiao", 1); 
        set_skill("literate", 1); 
        set_skill("martial-cognize", 1); 
        set_skill("jinchan-tunyue", 1);
        
        map_skill("force", "hamagong"); 
        map_skill("parry", "lingshe-zhangfa"); 
        map_skill("dodge", "chanchu-bufa"); 
        map_skill("staff", "lingshe-zhangfa"); 
        map_skill("cuff", "lingshe-quan"); 
        map_skill("finger", "shedu-qiqiao"); 
              
        prepare_skill("cuff", "lingshe-quan"); 
        prepare_skill("finger", "shedu-qiqiao"); 
        
        set("chat_chance_combat", 100); 
        set("chat_msg_combat", ({ 
                (: perform_action, "staff.qian" :), 
                (: perform_action, "staff.wuji" :), 
                (: perform_action, "strike.zhen" :), 
                (: perform_action, "strike.puji" :), 
                (: perform_action, "cuff.rou" :), 
                (: exert_function, "powerup" :), 
                (: exert_function, "recover" :), 
        }) ); 
        
        carry_object("/clone/weapon/gangzhang")->wield(); 
        carry_object("/clone/cloth/cloth")->wear(); 
} 
        
private void from_gaibang()
{
        set("scale", 130);
        set("from", ({
                "��˵����ԭ��ؤ�ﳤ�ϣ��书�߾���������������Ů�Ӷ���"
                + "������⣬�������ֽ�����������Ѫ���ȷ硣"
        }));

        set_skill("force", 1);
        set_skill("huntian-qigong", 1);
        set_skill("parry", 1);
        set_skill("dodge", 1);
        set_skill("xiaoyaoyou", 1);
        set_skill("staff", 1);
        set_skill("dagou-bang", 1);
        set_skill("strike", 1);
        set_skill("dragon-strike", 1);
        set_skill("literate", 1);
        set_skill("martial-cognize", 1);
        set_skill("bixue-danxin", 1);
        
        map_skill("force", "huntian-qigong");
        map_skill("parry", "dagou-bang");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("staff", "dagou-bang");
        map_skill("strike", "dragon-strike");

        prepare_skill("strike", "dragon-strike");

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
                (: perform_action, "staff.chan" :),
                (: perform_action, "staff.chuo" :),
                (: perform_action, "staff.feng" :),
                (: perform_action, "staff.ban" :),
                (: perform_action, "strike.lei" :),
                (: perform_action, "strike.hui" :),
        }) );

        set("class", "begger");

        carry_object("/clone/weapon/gangzhang")->wield();
        carry_object("/clone/misc/cloth")->wear();
}
         
private void from_taohua()
{
        set("scale", 135);
        set("from", ({
                "��˵���˺��һ�������ҩʦ��Щ��ϵ��",
        }));

        set_skill("force", 1);
        set_skill("bibo-shengong", 1);
        set_skill("parry", 1);
        set_skill("dodge", 1);
        set_skill("luoying-shenfa", 1);
        set_skill("sword", 1);
        set_skill("yuxiao-jianfa", 1);
        set_skill("strike", 1);
        set_skill("luoying-shenzhang", 1);
        set_skill("unarmed", 1);
        set_skill("xuanfeng-tui", 1);
        set_skill("hand", 1);
        set_skill("lanhua-shou", 1);
        set_skill("finger", 1);
        set_skill("tanzhi-shentong", 1);
        set_skill("literate", 1);
        set_skill("martial-cognize", 1);
        set_skill("qimen-xuanshu", 1);
        
        map_skill("force", "bibo-shengong");
        map_skill("dodge", "luoying-shenfa");
        map_skill("strike", "luoying-shenzhang");
        map_skill("hand", "lanhua-shou");
        map_skill("finger", "tanzhi-shentong");
        map_skill("throwing", "tanzhi-shentong");
        map_skill("unarmed", "xuanfeng-tui");
        map_skill("parry", "yuxiao-jianfa");
        map_skill("sword", "yuxiao-jianfa");

        prepare_skill("strike", "luoying-shenzhang");
        prepare_skill("unarmed", "xuanfeng-tui");

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
		(: perform_action, "sword.bihai" :),
		(: perform_action, "sword.qing" :),
		(: perform_action, "sword.tian" :),
		(: perform_action, "finger.ding" :),
		(: perform_action, "finger.xiao" :),
		(: perform_action, "finger.po" :),
		(: perform_action, "finger.zhuan" :),
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
        }) );

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
}
          
private void from_gumu()
{
        object ob;

        set("scale", 130);
        set("from", ({
                "��˵�������ֳ�Ӣ�ĵ��ӣ��������ʦ���ˡ�",
                "���˾�˵�ǹ�Ĺ���ˣ�����Ī������ԨԴ��",
        }));

        set_skill("force", 1);
        set_skill("yunv-xinfa", 1);
        set_skill("parry", 1);
        set_skill("dodge", 1);
        set_skill("yunv-shenfa", 1);
        set_skill("unarmed", 1);
        set_skill("meinv-quan", 1);
        set_skill("strike", 1);
        set_skill("fireice-strike", 1);
        set_skill("tianluo-diwang", 1);
        set_skill("throwing", 1);
        set_skill("yufeng-zhen", 1);
        set_skill("sword", 1);
        set_skill("yunv-jian", 1);
        set_skill("quanzhen-jian", 1);
        set_skill("literate", 1);
        set_skill("martial-cognize", 1);
        set_skill("zuoyou-hubo", 1);
        set_skill("taishang-wangqing", 1);		

        map_skill("force", "yunv-xinfa");
        map_skill("sword", "yunv-jian");
        map_skill("dodge", "yunv-shenfa");
        map_skill("parry", "meinv-quan");
        map_skill("unarmed", "meinv-quan");
        map_skill("strike", "tianluo-diwang");
        map_skill("throwing", "yufeng-zhen");

        prepare_skill("unarmed", "meinv-quan");
        prepare_skill("strike", "tianluo-diwang");

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
                (: perform_action, "strike.wang twice" :),
                (: perform_action, "sword.su twice" :),
                (: perform_action, "sword.lian twice" :),
                (: perform_action, "unarmed.you twice" :),
                (: perform_action, "throwing.ying twice" :),
        }) );

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
        ob = carry_object("/d/gumu/obj/yfzhen");
        ob->set_amount(300);
        set_temp("handing", ob);
}

private void from_xingxiu()
{
        set("scale", 130);
        set("from", ({
                "��˵�����������ɵ��ӣ���Ϊ���������ɣ�ֻ���ӳ������ɡ�",
        }));

        set_skill("force", 1);
        set_skill("huagong-dafa", 1);
        set_skill("guixi-gong", 1);
        set_skill("throwing", 1);
        set_skill("feixing-shu", 1);
        set_skill("dodge", 1);
        set_skill("zhaixinggong", 1);
        set_skill("strike", 1);
        set_skill("chousui-zhang", 1);
        set_skill("claw", 1);
        set_skill("sanyin-zhua", 1);
        set_skill("whip", 1);
        set_skill("chanhun-suo", 1);
        set_skill("parry", 1);
        set_skill("staff", 1);
        set_skill("poison", 1);
        set_skill("tianshan-zhang", 1);
        set_skill("xingxiu-qishu", 1);
        set_skill("literate", 1);
        set_skill("martial-cognize", 1);
        set_skill("bingchan-gong", 1);

        map_skill("force", "huagong-dafa");
        map_skill("dodge", "zhaixinggong");
        map_skill("strike", "chousui-zhang");
        map_skill("claw", "sanyin-zhua");
        map_skill("whip", "chanhun-suo");
        map_skill("parry", "tianshan-zhang");
        map_skill("staff", "tianshan-zhang");
        map_skill("poison", "xingxiu-qishu");
        
        prepare_skill("strike", "chousui-zhang");
        prepare_skill("claw", "sanyin-zhua");

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "staff.fugu" :),
                (: perform_action, "staff.xue" :),
                (: perform_action, "strike.shi" :),
                (: perform_action, "strike.huo" :),
                (: perform_action, "strike.tao" :),
                (: perform_action, "claw.zhua" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

        carry_object("/clone/weapon/gangzhang")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

private void from_xueshan()
{
        set("scale", 135);
        set("from", ({
                "��˵������ѩɽ�ɵĸ��֣�������ԭ�������޼ɣ��书�����˵á�",
        }));

        set_skill("force", 1);
        set_skill("longxiang-gong", 1);
        set_skill("mizong-neigong", 1);
        set_skill("dodge", 1);
        set_skill("shenkong-xing", 1);
        set_skill("cuff", 1);
        set_skill("yujiamu-quan", 1);
        set_skill("hand", 1);
        set_skill("dashou-yin", 1);
        set_skill("parry", 1);
        set_skill("staff", 1);
        set_skill("xiangmo-chu", 1);
        set_skill("lamaism", 1);
        set_skill("hammer", 1);
        set_skill("riyue-lun", 1);
        set_skill("literate", 1);
        set_skill("martial-cognize", 1);
        set_skill("mizong-zhenyan", 1);

        map_skill("force", "longxiang-gong");
        map_skill("dodge", "shenkong-xing");
        map_skill("cuff", "yujiamu-quan");
        map_skill("hand", "dashou-yin");
        map_skill("parry", "riyue-lun");
        map_skill("sword", "xiangmo-chu");
        map_skill("hammer", "riyue-lun");
        
        prepare_skill("unarmed", "longxiang-gong");
        prepare_skill("hand", "dashou-yin");
        prepare_skill("cuff", "yujiamu-quan");

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "hammer.po" :),
                (: perform_action, "hammer.yuan" :),
                (: perform_action, "hammer.lian" :),
                (: perform_action, "unarmed.tun" :),
                (: perform_action, "unarmed.die" :),
                (: perform_action, "unarmed.ji" :),
                (: exert_function, "recover" :),
                (: exert_function, "shield" :),
                (: exert_function, "powerup" :),
        }));

        set("class", "bonze");

        carry_object("/d/xueshan/obj/yinlun")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

private void from_xuedao() 
{ 
        set("scale", 135); 
        set("from", ({ 
                "��˵���˺�����Ѫ��������ʦ�ֵܣ�һ����ĺ�������", 
        })); 
        
        set_skill("force", 1); 
        set_skill("xuehai-mogong", 1); 
        set_skill("blade", 1); 
        set_skill("xuedao-daofa", 1); 
        set_skill("dodge", 1); 
        set_skill("shenkong-xing", 1); 
        set_skill("hand", 1); 
        set_skill("dashou-yin", 1); 
        set_skill("cuff", 1); 
        set_skill("yujiamu-quan", 1); 
        set_skill("parry", 1); 
        set_skill("lamaism", 1); 
        set_skill("literate", 1); 
        set_skill("martial-cognize", 1); 
        set_skill("xunying-dafa", 1);
        
        map_skill("force", "xuehai-mogong"); 
        map_skill("dodge", "shenkong-xing"); 
        map_skill("hand", "dashou-yin"); 
        map_skill("cuff", "yujiamu-quan"); 
        map_skill("parry", "xuedao-daofa"); 
        map_skill("blade", "xuedao-daofa"); 
        map_skill("sword", "mingwang-jian"); 
        
        prepare_skill("cuff", "yujiamu-quan"); 
        prepare_skill("hand", "dashou-yin"); 
        
        set("chat_chance_combat", 80); 
        set("chat_msg_combat", ({ 
                (: perform_action, "blade.ying" :), 
                (: perform_action, "blade.chi" :), 
                (: perform_action, "blade.xue" :), 
                (: perform_action, "blade.shi" :), 
                (: perform_action, "hand.yin" :), 
                (: perform_action, "cuff.jiang" :), 
                (: exert_function, "recover" :), 
                (: exert_function, "resurrect" :), 
                (: exert_function, "powerup" :), 
        })); 
        
        set("class", "bonze"); 
        
        carry_object("/clone/weapon/gangdao")->wield(); 
        carry_object("/clone/misc/cloth")->wear(); 
} 
        
private void from_xiaoyao() 
{ 
        set("scale", 135); 
        set("from", ({ 
                "��˵���˺���ң�������ӱ���ͬ�ŵ��ӣ�������֪�ιʷ����ɳ�", 
        })); 
        
        set_skill("force", 1); 
        set_skill("beiming-shengong", 1); 
        set_skill("dodge", 1); 
        set_skill("feiyan-zoubi", 1); 
        set_skill("liuyang-zhang", 1); 
        set_skill("parry", 1); 
        set_skill("sword", 1); 
        set_skill("liuyue-jian", 1); 
        set_skill("zhemei-shou", 1); 
        set_skill("hand", 1); 
        set_skill("strike", 1); 
        set_skill("literate", 1); 
        set_skill("martial-cognize", 1); 
        set_skill("xiaoyao-you", 1);
        
        map_skill("force", "beiming-shengong"); 
        map_skill("dodge", "feiyan-zoubi"); 
        map_skill("hand", "zhemei-shou"); 
        map_skill("strike", "liuyang-zhang"); 
        map_skill("parry", "liuyue-jian"); 
        map_skill("sword", "liuyue-jian"); 
        
        prepare_skill("hand","zhemei-shou"); 
        prepare_skill("strike","liuyang-zhang"); 
        
        set("class", "taoist"); 
        
        set("chat_chance_combat", 80); 
        set("chat_msg_combat", ({ 
                (: perform_action, "sword.liu" :), 
                (: perform_action, "sword.sheng" :), 
                (: perform_action, "hand.zhe" :), 
                (: perform_action, "hand.hai" :), 
                (: perform_action, "strike.zhong" :), 
                (: perform_action, "strike.huan" :), 
                (: exert_function, "recover" :), 
                (: exert_function, "shield" :), 
                (: exert_function, "powerup" :), 
        })); 
        
        carry_object("/clone/weapon/changjian")->wield(); 
        carry_object("/clone/misc/cloth")->wear(); 
} 
        
private void from_shenlong() 
{ 
        set("scale", 135); 
        set("from", ({ 
                "��˵��������������������״����ӣ������г������̣�����������", 
        })); 
        
        set_skill("force", 1); 
        set_skill("shenlong-xinfa", 1); 
        set_skill("dodge", 1); 
        set_skill("yixingbu", 1); 
        set_skill("hand", 1); 
        set_skill("shenlong-bashi", 1); 
        set_skill("strike", 1); 
        set_skill("huagu-mianzhang", 1); 
        set_skill("parry", 1); 
        set_skill("staff", 1); 
        set_skill("sword", 1); 
        set_skill("shedao-qigong", 1); 
        set_skill("literate", 1); 
        set_skill("martial-cognize", 1); 
        
        map_skill("force", "shenlong-xinfa"); 
        map_skill("dodge", "yixingbu"); 
        map_skill("hand", "shenlong-bashi"); 
        map_skill("strike", "huagu-mianzhang"); 
        map_skill("parry", "shedao-qigong"); 
        map_skill("staff", "shedao-qigong"); 
        
        prepare_skill("strike", "huagu-mianzhang"); 
        prepare_skill("hand", "shenlong-bashi"); 
        
        set("chat_chance_combat", 80); 
        set("chat_msg_combat", ({ 
                (: perform_action, "strike.hua" :), 
                (: perform_action, "hand.xian" :), 
                (: exert_function, "powerup" :), 
                (: exert_function, "recover" :), 
        })); 
        
        carry_object("/clone/misc/cloth")->wear(); 
} 

private void from_kunlun()
{
        set("scale", 135);
        set("from", ({
                "�����������죬��ͬ��һ���������ϣ���˵��������������ԨԴ��",
        }));

        set_skill("force", 1);
        set_skill("liangyi-shengong", 1);
        set_skill("dodge", 1);
        set_skill("chuanyun-bu", 1);
        set_skill("strike", 1);
        set_skill("kunlun-zhang", 1);
        set_skill("cuff", 1);
        set_skill("zhentian-quan", 1);
        set_skill("parry", 1);
        set_skill("sword", 1);
        set_skill("zhengliangyi-jian", 1);
        set_skill("qiankun-jian", 1);
        set_skill("literate", 1);
        set_skill("martial-cognize", 1);
        set_skill("kunlun-wuji", 1);

        map_skill("force", "liangyi-shengong");
        map_skill("dodge", "chuanyun-bu");
        map_skill("parry", "zhengliangyi-jian");
        map_skill("sword", "qiankun-jian");
        map_skill("strike", "kunlun-zhang");
        map_skill("cuff", "zhentian-quan");

        prepare_skill("strike", "kunlun-zhang");
        prepare_skill("cuff", "zhentian-quan");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "sword.qian" :),
                (: perform_action, "sword.riyue" :),
                (: perform_action, "sword.ni" :),
                (: perform_action, "strike.kong" :),
                (: perform_action, "cuff.shi" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),

        }));

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

private void from_yaowang()
{
        object ob;

        set("scale", 135);
        set("from", ({
                "��˵�����Ƕ�������ʯ�����Ĵ���ӣ����������˵á�",
        }));

        set_skill("force", 1);
        set_skill("shennong-xinjing", 1);
        set_skill("dodge", 1);
        set_skill("xuefu-mizong", 1);
        set_skill("strike", 1);
        set_skill("dusha-zhang", 1);
        set_skill("hand", 1);
        set_skill("lansha-shou", 1);
        set_skill("parry", 1);
        set_skill("staff", 1);
        set_skill("shennong-zhang", 1);
        set_skill("throwing", 1);
        set_skill("wuxing-jueming", 1);
        set_skill("poison", 1);
        set_skill("dispel-poison", 1);
        set_skill("medical", 1);
        set_skill("yaowang-miaoshu", 1);
        set_skill("literate", 1);
        set_skill("martial-cognize", 1);

        map_skill("force", "shennong-xinjing");
        map_skill("dodge", "xuefu-mizong");
        map_skill("strike", "dusha-zhang");
        map_skill("hand", "lansha-shou");
        map_skill("throwing", "wuxing-jueming");
        map_skill("parry", "shennong-zhang");
        map_skill("staff", "shennong-zhang");
        map_skill("poison", "dispel-poison");
        map_skill("medical", "yaowang-miaoshu");

        prepare_skill("hand", "lansha-shou");
        prepare_skill("strike", "dusha-zhang");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "staff.lun" :),
                (: perform_action, "throwing.hun" :),
                (: perform_action, "strike.meng" :),
                (: perform_action, "hand.po" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),

        }));

        carry_object("/clone/weapon/gangzhang")->wield();
        carry_object("/clone/misc/cloth")->wear();
        ob = carry_object("/clone/weapon/jili");
        ob->set_amount(50);
        set_temp("handing", ob);
}

private void from_wudu()
{
        object ob;

        set("scale", 135);
        set("from", ({
                "����ԭΪ�����嶾�̳��ϣ���֪��ιʶ��뿪�嶾�̡�",
        }));

        set_skill("force", 1);
        set_skill("xiuluo-yinshagong", 1);
        set_skill("dodge", 1);
        set_skill("jinshe-youshenbu", 1);
        set_skill("strike", 1);
        set_skill("tianchan-zhang", 1);
        set_skill("claw", 1);
        set_skill("wusheng-zhao", 1);
        set_skill("parry", 1);
        set_skill("whip", 1);
        set_skill("ruanhong-zhusuo", 1);
        set_skill("poison", 1);
        set_skill("wudu-qishu", 1);
        set_skill("literate", 1);
        set_skill("martial-cognize", 1);
        set_skill("wudu-jing", 1);

        map_skill("force", "xiuluo-yinshagong");
        map_skill("dodge", "jinshe-youshenbu");
        map_skill("strike", "tianchan-zhang");
        map_skill("claw", "wusheng-zhao");
        map_skill("parry", "ruanhong-zhusuo");
        map_skill("whip", "ruanhong-zhusuo");
        map_skill("poison", "wudu-qishu");

        prepare_skill("claw", "wusheng-zhao");
        prepare_skill("strike", "tianchan-zhang");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "whip.teng" :),
                (: perform_action, "whip.pan" :),
                (: perform_action, "whip.bohu" :),
                (: perform_action, "whip.suo" :),
                (: perform_action, "claw.lian" :),
                (: perform_action, "strike.chan" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),

        }));

        carry_object("/clone/weapon/changbian")->wield();
        carry_object("/clone/misc/cloth")->wear();

        ob = carry_object("/clone/misc/chongdu");
        ob->set_amount(50);
        ob->set("poison", ([
                "level" : query_skill("poison", 1),
                "id"    : query("id"),
                "name"  : "�涾",
                "duration" : 300,
        ]));
        set_temp("handing", ob);

}

private void from_lingxiao()
{
        set("scale", 140);
        set("from", ({
                "�����˴�ѩɽ�����Ǹ��֣����������±䣬�����ɶ�ȥ��",
        }));

        set_skill("force", 1);
        set_skill("wuwang-shengong", 1);
        set_skill("dodge", 1);
        set_skill("taxue-wuhen", 1);
        set_skill("cuff", 1);
        set_skill("lingxiao-quan", 1);
        set_skill("strike", 1);
        set_skill("piaoxu-zhang", 1);
        set_skill("sword", 1);
        set_skill("xueshan-jian", 1);
        set_skill("parry", 1);
        set_skill("literate", 1);
        set_skill("martial-cognize", 1);

        map_skill("force", "wuwang-shengong");
        map_skill("dodge", "taxue-wuhen");
        map_skill("cuff", "lingxiao-quan");
        map_skill("strike", "piaoxu-zhang");
        map_skill("sword", "xueshan-jian");
        map_skill("parry", "xueshan-jian");

        prepare_skill("strike", "piaoxu-zhang");
        prepare_skill("cuff", "lingxiao-quan");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "sword.hui" :),
                (: perform_action, "sword.chu" :),
                (: perform_action, "sword.feng" :),
                (: perform_action, "cuff.jue" :),
                (: perform_action, "cuff.san" :),
                (: perform_action, "strike.piao" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
}


private void from_tiezhang()
{
        set("scale", 120);
        set("from", ({
                "���������ư����³��ϣ�����ǧ��֮����ɽ���¡�",
        }));

        set_skill("force", 1);
        set_skill("tianlei-shengong", 1);
        set_skill("dodge", 1);
        set_skill("dengping-dushui", 1);
        set_skill("strike", 1);
        set_skill("parry", 1);
        set_skill("tie-zhang", 1);
        set_skill("feilong-zhang", 1);
        set_skill("staff", 1);
        set_skill("literate", 1);
        set_skill("martial-cognize", 1);
        set_skill("tiezhang-shuishangpiao", 1);

        map_skill("force", "tianlei-shengong");
        map_skill("strike", "tie-zhang");
        map_skill("parry", "tie-zhang");
        map_skill("dodge", "dengping-dushui");
        map_skill("staff", "feilong-zhang");

        prepare_skill("strike", "tie-zhang");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "strike.long" :),
                (: perform_action, "strike.lei" :),
                (: perform_action, "strike.dao" :),
                (: perform_action, "strike.yin" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

        carry_object("/clone/misc/cloth")->wear();
}


private void from_zhenyuan()
{
        object ob;

        set("scale", 135);
        set("from", ({
                "��������ά���ʦ�֣�������ԵĹ�������¯���ࡣ",
        }));

        set_skill("parry", 1);
        set_skill("wai-bagua", 1);
        set_skill("force", 1);
        set_skill("nei-bagua", 1);
        set_skill("dodge", 1);
        set_skill("bagua-bu", 1);
        set_skill("strike", 1);
        set_skill("bagua-zhang", 1);
        set_skill("cuff", 1);
        set_skill("bagua-quan", 1);
        set_skill("blade", 1);
        set_skill("bagua-dao", 1);
        set_skill("throwing", 1);
        set_skill("bagua-biao", 1);
        set_skill("literate", 1);
        set_skill("martial-cognize", 1);

        map_skill("dodge", "bagua-bu");
        map_skill("force", "nei-bagua");
        map_skill("strike", "bagua-zhang");
        map_skill("blade", "bagua-dao");
        map_skill("cuff", "bagua-quan");
        map_skill("parry", "wai-bagua");
        map_skill("throwing", "bagua-biao");

        prepare_skill("cuff", "bagua-quan");
        prepare_skill("strike", "bagua-zhang");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "blade.mang" :),
                (: perform_action, "blade.tian" :),
                (: perform_action, "blade.sha" :),
                (: perform_action, "cuff.gua" :),
                (: perform_action, "strike.ding" :),
                (: perform_action, "strike.jia" :),
                (: perform_action, "parry.zhen" :),
                (: perform_action, "throwing.zhi" :),
                (: perform_action, "throwing.xian" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

        carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/clone/misc/cloth")->wear();
        ob = carry_object("/clone/weapon/feihuangshi");
        ob->set_amount(80);
        set_temp("handing", ob);
}

private void from_xuanming()
{
        object ob;

        set("scale", 135);
        set("from", ({
                "�����˰�����˵�ʦ�֣���ڤ��������¯���ࡣ",
        }));

        set_skill("parry", 1);
        set_skill("xuanming-shengong", 1);
        set_skill("force", 1);
        set_skill("minggu-xinfa", 1);
        set_skill("dodge", 1);
        set_skill("liuying-bu", 1);
        set_skill("strike", 1);
        set_skill("xuanming-zhang", 1);
        set_skill("literate", 1);
        set_skill("martial-cognize", 1);

        map_skill("dodge", "liuying-bu");
        map_skill("force", "xuanming-shengong");
        map_skill("strike", "xuanming-zhang");
        map_skill("parry", "xuanming-zhang");

        prepare_skill("strike", "xuanming-zhang");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "strike.ying" :),
                (: perform_action, "strike.lang" :),
                (: perform_action, "strike.zhe" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

        carry_object("/clone/misc/cloth")->wear();
}

private void from_lingjiu() 
{  
        set("scale", 130);
        set("from", ({   
                "���������չ�����ͽ����������������", 
        }));

        set_skill("force", 1);
        set_skill("bahuang-gong", 1);
        set_skill("dodge", 1);
        set_skill("yueying-wubu", 1);
        set_skill("strike", 1);
        set_skill("liuyang-zhang", 1);
        set_skill("hand", 1);
        set_skill("zhemei-shou", 1);
        set_skill("sword", 1);
        set_skill("tianyu-qijian", 1);
        set_skill("literate", 1);
        set_skill("martial-cognize", 1);
        set_skill("fanlao-huantong", 1);

        map_skill("force", "bahuang-gong"); 
        map_skill("dodge", "yueying-wubu"); 
        map_skill("strike", "liuyang-zhang"); 
        map_skill("hand", "zhemei-shou"); 
        map_skill("sword", "tianyu-qijian"); 
        map_skill("parry", "tianyu-qijian"); 

        prepare_skill("strike", "liuyang-zhang");
        prepare_skill("hand", "zhemei-shou"); 

        set("chat_chance_combat", 80); 
        set("chat_msg_combat", ({  
                (: exert_function, "recover" :),  
                (: exert_function, "powerup" :),  
                (: perform_action, "hand.zhe" :), 
                (: perform_action, "sword.san" :), 
                (: perform_action, "sword.zhu" :), 
                (: perform_action, "strike.huan" :), 
                (: perform_action, "strike.po" :), 
        }));

        carry_object("/clone/weapon/changjian")->wield(); 
        carry_object("/clone/misc/cloth")->wear();
}  

private void from_mingjiao()
{ 
        set("scale", 130);
        set("from", ({  
                "���������̵���ͽ����������������", 
        }));

        set_skill("force", 1);
        set_skill("shenghuo-shengong", 1);
        set_skill("dodge", 1);
        set_skill("qingfu-shenfa", 1);
        set_skill("claw", 1);
        set_skill("sougu-yingzhua", 1);
        set_skill("shenghuo-ling", 1);
        set_skill("parry", 1);  
        set_skill("sword", 1);
        set_skill("parry", 1);
        set_skill("literate", 1);
        set_skill("martial-cognize", 1);
        set_skill("guangming-jing", 1); 

        map_skill("parry", "shenghuo-ling"); 
        map_skill("sword", "shenghuo-ling"); 
        map_skill("dodge", "qingfu-shenfa"); 
        map_skill("force", "shenghuo-shengong"); 
        map_skill("claw", "sougu-yingzhua"); 

        prepare_skill("claw", "sougu-yingzhua"); 

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({  
                  (: perform_action, "sword.hua" :),  
                  (: perform_action, "sword.can" :),  
                  (: perform_action, "sword.lian" :),  
                  (: perform_action, "sword.xi" :),  
                  (: perform_action, "claw.xue" :),  
                  (: exert_function, "powerup" :), 
                  (: exert_function, "recover" :), 
        }));

        carry_object("/clone/weapon/changjian")->wield(); 
        carry_object("/clone/misc/cloth")->wear(); 
}

private void from_quanzhen() 
{ 
        set("scale", 150); 
        set("from", ({ 
               "��˵���˳���ȫ�棬��ȫ���ɸ��֡�", 
               "��˵�������������ĵ��ӣ��������ʦ���ˡ�", 
        }));

        set_skill("force", 1); 
        set_skill("xiantian-gong", 1); 
        set_skill("jinyan-gong", 1); 
        set_skill("dodge", 1); 
        set_skill("strike", 1); 
        set_skill("finger", 1); 
        set_skill("sword", 1); 
        set_skill("quanzhen-jian", 1); 
        set_skill("haotian-zhang", 1); 
        set_skill("zhongnan-zhi", 1); 
        set_skill("parry", 1); 
        set_skill("zuoyou-hubo", 1);
        set_skill("literate", 1);
        set_skill("martial-cognize", 1);
        set_skill("huajia-su", 1); 
        
        map_skill("force", "xiantian-gong"); 
        map_skill("dodge", "jinyan-gong"); 
        map_skill("strike", "haotian-zhang"); 
        map_skill("finger", "zhongnan-zhi"); 
        map_skill("sword", "quanzhen-jian"); 
        map_skill("parry", "quanzhen-jian"); 

        prepare_skill("finger", "zhongnan-zhi"); 
        prepare_skill("strike", "haotian-zhang"); 
        prepare_skill("unarmed", "xiantian-gong"); 

        set("chat_chance_combat", 80); 
        set("chat_msg_combat", ({ 
                (: exert_function, "powerup" :), 
                (: exert_function, "recover" :), 
                (: exert_function, "hup" :), 
                (: perform_action, "sword.ding" :), 
                (: perform_action, "sword.chan" :), 
                (: perform_action, "strike.ju" :), 
                (: perform_action, "finger.zhi" :), 
                (: perform_action, "unarmed.dang" :), 
                (: perform_action, "unarmed.fen" :), 
                (: perform_action, "unarmed.xian" :), 
        }));

        carry_object("/clone/weapon/changjian")->wield(); 
        carry_object("/clone/misc/cloth")->wear(); 
}

private void from_emei()
{
        object ob;

        set("scale", 130);
        set("from", ({ 
               "��˵���������ʦ̫�ĵ��ӣ��������ʦ���ˡ�", 
               "�������ʦ̫�ĵ��ӣ����ĺ������ĵ��ӡ�", 
        })); 

       set_skill("force", 1); 
       set_skill("linji-zhuang", 1); 
       set_skill("parry", 1); 
       set_skill("dodge", 1); 
       set_skill("zhutian-bu", 1); 
       set_skill("sword", 1); 
       set_skill("huifeng-jian", 1); 
       set_skill("finger", 1); 
       set_skill("tiangang-zhi", 1); 
       set_skill("strike", 1); 
       set_skill("jinding-zhang", 1); 
       set_skill("literate", 1);
       set_skill("martial-cognize", 1);
       set_skill("jingxin", 1);

       map_skill("force", "linji-zhuang"); 
       map_skill("dodge", "zhutian-bu"); 
       map_skill("sword", "huifeng-jian"); 
       map_skill("parry", "huifeng-jian"); 
       map_skill("finger", "tiangang-zhi"); 
       map_skill("strike", "jinding-zhang"); 

       prepare_skill("strike", "jinding-zhang"); 
       prepare_skill("finger", "tiangang-zhi"); 

       set("chat_chance_combat", 80);
       set("chat_msg_combat", ({ 
                 (: perform_action, "sword.mie" :), 
                 (: perform_action, "sword.jue" :), 
                 (: perform_action, "finger.ling" :), 
                 (: exert_function, "recover" :), 
                 (: exert_function, "powerup" :), 
        })); 

        set("class", "taoism"); 

        carry_object("/clone/weapon/changjian")->wield(); 
        carry_object("/clone/misc/cloth")->wear(); 
} 

private void from_murong() 
{ 
        object ob;

        set("scale", 130);
        set("from", ({  
               "��˵������Ľ���ɵ��ӣ����ڱ���ʦ�ţ���������������",  
        }));  

        set_skill("force", 1);
        set_skill("shenyuan-gong", 1);
        set_skill("dodge", 1);
        set_skill("beidou-xianzong", 1);
        set_skill("parry", 1);
        set_skill("douzhuan-xingyi", 1);
        set_skill("sword", 1);
        set_skill("murong-jianfa", 1);
        set_skill("cuff", 1);
        set_skill("qixing-quan", 1);
        set_skill("finger", 1);
        set_skill("canhe-zhi", 1);
        set_skill("literate", 1);
        set_skill("martial-cognize", 1);
        set_skill("huitong-tianxia", 1);

        map_skill("force", "shenyuan-gong");  
        map_skill("dodge", "beidou-xianzong");  
        //map_skill("parry", "douzhuan-xingyi");  
        map_skill("parry", "murong-jianfa");  
        map_skill("sword", "murong-jianfa");  
        map_skill("cuff", "qixing-quan");  
        map_skill("finger", "canhe-zhi");  

        prepare_skill("cuff", "qixing-quan");
        prepare_skill("finger", "canhe-zhi");

        set("chat_chance_combat", 80);  
        set("chat_msg_combat", ({  
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
                (: perform_action, "sword.xing" :),  
                (: perform_action, "sword.hong" :),  
                (: perform_action, "finger.canhe" :),  
                (: perform_action, "finger.zhi" :),  
                (: perform_action, "finger.you" :),  
        })); 

        carry_object("/clone/weapon/changjian")->wield();  
        carry_object("/clone/misc/cloth")->wear();  
}

private void from_hujia()
{  
        object ob; 

       set("scale", 130); 
       set("from", ({   
              "��˵�����Ǻ��ҵ��ӣ�����ʦ�ţ������С�",   
       }));

       set_skill("force", 1); 
       set_skill("lengyue-shengong", 1); 
       set_skill("dodge", 1); 
       set_skill("sixiang-bufa", 1); 
       set_skill("cuff", 1); 
       set_skill("hujia-quan", 1); 
       set_skill("strike", 1); 
       set_skill("tianchang-zhang", 1); 
       set_skill("blade", 1); 
       set_skill("hujia-daofa", 1); 
       set_skill("parry", 1); 
       set_skill("literate", 1);
       set_skill("martial-cognize", 1);
       set_skill("daojian-xiaotianwai", 1); 

       map_skill("force", "lengyue-shengong");   
       map_skill("dodge", "sixiang-bufa");   
       map_skill("cuff", "hujia-quan");   
       map_skill("strike", "tianchang-zhang");   
       map_skill("blade", "hujia-daofa");   
       map_skill("parry", "hujia-daofa");   

       prepare_skill("cuff", "hujia-quan"); 
       prepare_skill("strike", "tianchang-zhang"); 

       set("chat_chance_combat", 80);  
       set("chat_msg_combat", ({   
               (: perform_action, "blade.cang" :),  
               (: perform_action, "blade.pi" :),  
               (: perform_action, "blade.po" :),  
               (: perform_action, "blade.zhui" :),  
               (: perform_action, "blade.xian" :),  
               (: perform_action, "cuff.kuai" :),  
               (: exert_function, "recover" :),  
               (: exert_function, "powerup" :),  
       }));

       carry_object("/clone/weapon/gangdao")->wield();  
       carry_object("/clone/misc/cloth")->wear();   
} 

private void from_duanshi()
{
        set("scale", 135); 
        set("from", ({ 
               "��˵���˺Ͷμ���Щ��ϵ��", 
        }));

        set_skill("force", 1); 
        set_skill("kurong-changong", 1); 
        set_skill("sword", 1); 
        set_skill("duanjia-jian", 1); 
        set_skill("parry", 1); 
        set_skill("dodge", 1); 
        set_skill("cuff", 1); 
        set_skill("tiannan-bu", 1); 
        set_skill("jinyu-quan", 1); 
        set_skill("strike", 1); 
        set_skill("wuluo-zhang", 1); 
        set_skill("sun-finger", 1); 
        set_skill("finger", 1); 
        set_skill("literate", 1);
        set_skill("martial-cognize", 1);
        set_skill("qimai-liuzhuan", 1); 

        map_skill("force", "kurong-changong");    
        map_skill("sword", "duanjian-jian");    
        map_skill("cuff", "jinyu-quan");    
        map_skill("strike", "wuluo-zhang");    
        map_skill("finger", "sun-finger");    
        map_skill("dodge", "tiannan-bu");    
        map_skill("parry", "duanjian-jian");    

        prepare_skill("finger", "sun-finger");     

        set("chat_chance_combat", 80); 
        set("chat_msg_combat", ({   
                (: exert_function, "powerup" :), 
                (: exert_function, "recover" :), 
                (: perform_action, "sword.jing" :), 
                (: perform_action, "sword.lian" :), 
                (: perform_action, "finger.qian" :), 
                (: perform_action, "finger.die" :), 
                (: perform_action, "finger.dian" :), 
        }));

        carry_object("/clone/weapon/changjian")->wield(); 
        carry_object("/clone/misc/cloth")->wear();   
} 

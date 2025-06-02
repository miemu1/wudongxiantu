//��Ӧ�������ݱ�
mapping weapon_file =
([
    "sword" : "/clone/weapon/gangjian",   //�ֽ�
    "blade" : "/clone/weapon/gangdao",    //�ֵ�
    "dadao" : "/clone/weapon/dadao",      //��
    "staff" : "/clone/weapon/gangzhang",  //����
    "qiang" : "/clone/weapon/changqiang", //��ǹ
    "axe"   : "/clone/weapon/tiefu",      //����
    "fork"  : "/clone/weapon/gangcha",    //�ֲ�
    "whip"  : "/clone/weapon/changbian",  //����
    "wodao" : "/clone/weapon/wodao",      //����
    "xiyang-jian" : "/clone/weapon/xiyang-jian",    //����
]);

//�������ƶ��ձ�
mapping weapon_type =
([
    "axe"     : "����",
    "blade"   : "����",
    "claw"    : "צ��",
    "dadao"   : "����",
    "fork"    : "�淨",
    "finger"  : "ָ��",
    "qiang"   : "ǹ��",
    "staff"   : "�ȷ�",
    "sword"   : "����",
    "unarmed" : "ȭ��",
    "whip"    : "�޷�",
]);

//����������ݱ�
mapping *all_skill = ({
([
    "faction" : "����",             //��������
    "name"    : "�����ȷ�",         //��������
    "code"    : "baituo_1",         //���ܴ���
    "weapon"  : "staff",            //��������
    "gender"  : "all",              //�Ա�����
    "horse"   : 0,                  //��������
    "m_skill" : ([                  //����ӳ��
                    "unarmed" : "shexing-diaoshou",
                    "dodge"   : "chanchu-bufa",
                    "parry"   : "lingshe-zhangfa",
                    "staff"   : "lingshe-zhangfa",
                    "force"   : "hamagong",
                ]),
    "p_skill" : ([]),               //Ԥ������
    "special" : ([                  //������
                    "weapon/she" :  30,
                    "weapon/id"  : "gang zhang",
                ]),
]),
([
    "faction" : "����",
    "name"    : "�ط������",
    "code"    : "emei_1",
    "weapon"  : "sword",
    "gender"  : "female",
    "m_skill" : ([
                    "force"   : "jiuyin-shengong",
                    "sword"   : "huifeng-jian",
                    "parry"   : "huifeng-jian",
                    "unarmed" : "piaoxue-zhang",
                    "claw"    : "jieshou-jiushi",
                    "dodge"   : "anying-fuxiang",
                ]),
    "p_skill" : ([
                    "unarmed" : "piaoxue-zhang",
                    "claw"    : "jieshou-jiushi",
                ]),
]),
([
    "faction" : "����",
    "name"    : "��������צ",
    "code"    : "emei_2",
    "weapon"  : "claw",
    "gender"  : "female",
    "m_skill" : ([
                    "force"   : "jiuyin-shengong",
                    "parry"   : "jiuyin-baiguzhao",
                    "claw"    : "jiuyin-baiguzhao",
                    "dodge"   : "anying-fuxiang",
                ]),
    "p_skill" : ([
                    "claw"    : "jiuyin-baiguzhao",
                ]),
]),
([
    "faction" : "ؤ��",
    "name"    : "����ʮ����",
    "code"    : "gaibang_1",
    "weapon"  : "unarmed",
    "gender"  : "all",
    "m_skill" : ([
                    "unarmed" : "xianglong-zhang",
                    "dodge"   : "xiaoyaoyou",
                    "parry"   : "xianglong-zhang",
                    "force"   : "huntian-qigong",
                ]),
]),
([
    "faction" : "ؤ��",
    "name"    : "�򹷰���",
    "code"    : "gaibang_2",
    "weapon"  : "staff",
    "gender"  : "all",
    "m_skill" : ([
                    "unarmed" : "xianglong-zhang",
                    "dodge"   : "xiaoyaoyou",
                    "parry"   : "dagou-bang",
                    "staff"   : "dagou-bang",
                    "force"   : "huntian-qigong",
                ]),
]),
([
    "faction" : "��ɽ",
    "name"    : "��ɽ����",
    "code"    : "huashan_1",
    "weapon"  : "sword",
    "gender"  : "all",
    "m_skill" : ([
                    "unarmed" : "hunyuan-zhang",
                    "dodge"   : "huashan-shenfa",
                    "parry"   : "huashan-jianfa",
                    "sword"   : "huashan-jianfa",
                    "force"   : "zixia-shengong",
                ]),
    "special" : ([
                    "huashan_marks/ningshi" : 1,
                ]),
]),
([
    "faction" : "��ɽ",
    "name"    : "���ǵ���",
    "code"    : "huashan_2",
    "weapon"  : "blade",
    "gender"  : "all",
    "m_skill" : ([
                    "unarmed" : "hunyuan-zhang",
                    "dodge"   : "huashan-shenfa",
                    "parry"   : "liangyi-daofa",
                    "blade"   : "liangyi-daofa",
                    "force"   : "zixia-shengong",
                ]),
]),
([
    "faction" : "����",
    "name"    : "���ǽ���",
    "code"    : "kunlun_1",
    "weapon"  : "sword",
    "gender"  : "all",
    "m_skill" : ([
                    "unarmed" : "kunlun-zhang",
                    "dodge"   : "yingxian-bu",
                    "parry"   : "liangyi-jian",
                    "sword"   : "liangyi-jian",
                    "force"   : "jingshen-jue",
                ]),
]),
([
    "faction" : "����",
    "name"    : "�����潣",
    "code"    : "lingjiu_1",
    "weapon"  : "sword",
    "gender"  : "female",
    "m_skill" : ([
                    "claw"    : "zhemei-shou",
                    "dodge"   : "yueying-wubu",
                    "parry"   : "tianyu-qijian",
                    "sword"   : "tianyu-qijian",
                    "force"   : "bahuang-gong",
                ]),
    "p_skill" : ([
                    "claw"    : "zhemei-shou",
                ]),
]),
([
    "faction" : "���",
    "name"    : "�ɷ罣��",
    "code"    : "qingcheng_1",
    "weapon"  : "sword",
    "gender"  : "male",
    "m_skill" : ([
                    "unarmed" : "cuixin-zhang",
                    "dodge"   : "chonghe-bufa",
                    "parry"   : "songfeng-jianfa",
                    "sword"   : "songfeng-jianfa",
                    "force"   : "qingcheng-xinfa",
                ]),
]),
([
    "faction" : "ȫ��",
    "name"    : "ȫ�潣��",
    "code"    : "quanzhen_1",
    "weapon"  : "sword",
    "gender"  : "all",
    "m_skill" : ([
                    "unarmed"  : "sanhua-judingzhang",
                    "dodge"    : "jinyan-gong",
                    "parry"    : "quanzhen-jianfa",
                    "sword"    : "quanzhen-jianfa",
                    "force"    : "xuanmen-neigong",
                ]),
]),
([
    "faction" : "����",
    "name"    : "��Ħ����",
    "code"    : "shaolin_1",
    "weapon"  : "sword",
    "gender"  : "male",
    "m_skill" : ([
                    "finger"  : "nianhua-zhi",
                    "dodge"   : "shaolin-shenfa",
                    "parry"   : "damo-jian",
                    "sword"   : "damo-jian",
                    "force"   : "hunyuan-yiqi",
                ]),
    "p_skill" : ([
                    "finger"  : "nianhua-zhi",
                ]),
]),
([
    "faction" : "����",
    "name"    : "�黨ָ��",
    "code"    : "shaolin_2",
    "weapon"  : "finger",
    "gender"  : "male",
    "m_skill" : ([
                    "dodge"   : "shaolin-shenfa",
                    "parry"   : "nianhua-zhi",
                    "finger"  : "nianhua-zhi",
                    "force"   : "hunyuan-yiqi",
                ]),
    "p_skill" : ([
                    "finger"  : "nianhua-zhi",
                ]),
    "special" : ([]),
]),
([
    "faction" : "����",
    "name"    : "���±޷�",
    "code"    : "shaolin_3",
    "weapon"  : "whip",
    "gender"  : "male",
    "m_skill" : ([
                    "finger"  : "nianhua-zhi",
                    "dodge"   : "shaolin-shenfa",
                    "parry"   : "riyue-bian",
                    "whip"    : "riyue-bian",
                    "force"   : "hunyuan-yiqi",
                ]),
    "p_skill" : ([
                    "finger"  : "nianhua-zhi",
                ]),
]),
([
    "faction" : "����",
    "name"    : "�ߵ��潣",
    "code"    : "shenlong_1",
    "weapon"  : "sword",
    "gender"  : "all",
    "m_skill" : ([
                    "unarmed"  : "shenlong-bashi",
                    "dodge"    : "yixingbu",
                    "parry"    : "shedao-qijian",
                    "sword"    : "shedao-qijian",
                    "force"    : "shenlong-zhanqi",
                ]),
]),
([
    "faction" : "����",
    "name"    : "������ʽ",
    "code"    : "shenlong_2",
    "weapon"  : "unarmed",
    "gender"  : "all",
    "m_skill" : ([
                    "unarmed"  : "shenlong-bashi",
                    "parry"    : "shenlong-bashi",
                    "dodge"    : "yixingbu",
                    "force"    : "shenlong-zhanqi",
                ]),
]),
([
    "faction" : "�һ�",
    "name"    : "��Ӣ��",
    "code"    : "taohua_1",
    "weapon"  : "sword",
    "gender"  : "all",
    "m_skill" : ([
                    "unarmed"  : "luoying-zhang",
                    "dodge"    : "anying-fuxiang",
                    "parry"    : "luoying-shenjian",
                    "sword"    : "luoying-shenjian",
                    "force"    : "bibo-shengong",
                ]),
]),
([
    "faction" : "�һ�",
    "name"    : "�����׹�צ",
    "code"    : "taohua_2",
    "weapon"  : "claw",
    "gender"  : "all",
    "m_skill" : ([
                    "claw"    : "jiuyin-baiguzhao",
                    "dodge"   : "anying-fuxiang",
                    "parry"   : "jiuyin-baiguzhao",
                    "force"   : "bibo-shengong",
                ]),
    "p_skill" : ([
                    "claw"    : "jiuyin-baiguzhao",
                ]),
]),
([
    "faction" : "�䵱",
    "name"    : "̫������",
    "code"    : "wudang_1",
    "weapon"  : "sword",
    "gender"  : "all",
    "m_skill" : ([
                    "unarmed" : "taiji-quan",
                    "dodge"   : "tiyunzong",
                    "parry"   : "taiji-jian",
                    "sword"   : "taiji-jian",
                    "force"   : "taiji-shengong",
                ]),
]),
([
    "faction" : "���",
    "name"    : "���ǹ��",
    "code"    : "wuguan_1",
    "weapon"  : "qiang",
    "gender"  : "all",
    "horse"   : 1,
    "m_skill" : ([
                    "unarmed" : "taizu-changquan",
                    "dodge"   : "tianma-xingkong",
                    "parry"   : "yangjia-qiang",
                    "qiang"   : "yangjia-qiang",
                    "force"   : "longhu-baqi",
                ]),
]),
([
    "faction" : "���",
    "name"    : "�����",
    "code"    : "wuguan_2",
    "weapon"  : "dadao",
    "gender"  : "all",
    "horse"   : 1,
    "m_skill" : ([
                    "unarmed" : "taizu-changquan",
                    "dodge"   : "tianma-xingkong",
                    "parry"   : "chunqiu-dadao",
                    "blade"   : "chunqiu-dadao",
                    "force"   : "longhu-baqi",
                ]),
]),
([
    "faction" : "���",
    "name"    : "����淨",
    "code"    : "wuguan_3",
    "weapon"  : "fork",
    "gender"  : "all",
    "horse"   : 1,
    "m_skill" : ([
                    "unarmed" : "taizu-changquan",
                    "dodge"   : "tianma-xingkong",
                    "fork"    : "tuotian-cha",
                    "parry"   : "tuotian-cha",
                    "force"   : "longhu-baqi",
                ]),
]),
([
    "faction" : "���",
    "name"    : "��ħ����",
    "code"    : "wuguan_4",
    "weapon"  : "axe",
    "gender"  : "all",
    "horse"   : 1,
    "m_skill" : ([
                    "unarmed" : "taizu-changquan",
                    "dodge"   : "tianma-xingkong",
                    "parry"   : "fengmo-fu",
                    "axe"     : "fengmo-fu",
                    "force"   : "longhu-baqi",
                ]),
]),
([
    "faction" : "����",
    "name"    : "��������",
    "code"    : "yunlong_1",
    "weapon"  : "sword",
    "gender"  : "all",
    "m_skill" : ([
                    "unarmed" : "yunlong-shou",
                    "claw"    : "yunlong-zhua",
                    "dodge"   : "yunlong-shenfa",
                    "parry"   : "yunlong-jian",
                    "sword"   : "yunlong-jian",
                    "force"   : "yunlong-shengong",
                ]),
    "p_skill" : ([
                    "claw"    : "yunlong-zhua",
                    "unarmed" : "yunlong-shou",
                ]),
]),
([
    "faction" : "����",
    "name"    : "�����޷�",
    "code"    : "yunlong_2",
    "weapon"  : "whip",
    "gender"  : "all",
    "m_skill" : ([
                    "unarmed" : "yunlong-shou",
                    "claw"    : "yunlong-zhua",
                    "dodge"   : "yunlong-shenfa",
                    "parry"   : "yunlong-bian",
                    "whip"    : "yunlong-bian",
                    "force"   : "yunlong-shengong",
                ]),
    "p_skill" : ([
                    "claw"    : "yunlong-zhua",
                    "unarmed" : "yunlong-shou",
                ]),
]),
([
    "faction" : "����",
    "name"    : "�廢���ŵ�",
    "code"    : "yunlong_3",
    "weapon"  : "blade",
    "gender"  : "all",
    "m_skill" : ([
                    "unarmed" : "yunlong-shou",
                    "claw"    : "yunlong-zhua",
                    "dodge"   :"yunlong-shenfa",
                    "parry"   : "wuhu-duanmendao",
                    "blade"   : "wuhu-duanmendao",
                    "force"   : "yunlong-shengong",
                ]),
    "p_skill" : ([
                    "claw"    : "yunlong-zhua",
                    "unarmed" : "yunlong-shou",
                ]),
]),
([
    "faction" : "����",
    "name"    : "��Ѫ��ץ",
    "code"    : "yunlong_4",
    "weapon"  : "claw",
    "gender"  : "all",
    "m_skill" : ([
                    "unarmed" : "yunlong-shou",
                    "claw"    : "yunlong-zhua",
                    "dodge"   : "yunlong-shenfa",
                    "parry"   : "yunlong-shou",
                    "force"   : "yunlong-shengong",
                ]),
    "p_skill" : ([
                    "claw"    : "yunlong-zhua",
                    "unarmed" : "yunlong-shou",
                ]),
]),
([
    "faction" : "����",
    "name"    : "�������",
    "code"    : "wokou",
    "weapon"  : "wodao",
    "gender"  : "male",
    "nation"  : "�ձ�",
    "no_list" : 1,
    "m_skill" : ([
                    "blade"   : "wo-dao",
                    "unarmed" : "dongying-renshu",
                    "dodge"   : "dongying-renshu",
                    "parry"   : "wo-dao",
                    "force"   : "jidao-shaqi",
                ]),
]),
([
    "faction" : "����",
    "name"    : "���󲫻�",
    "code"    : "xiyang",
    "weapon"  : "xiyang-jian",
    "gender"  : "male",
    "nation"  : "ŷ��",
    "no_list" : 1,
    "m_skill" : ([
                    "sword"   : "xiyang-jian",
                    "unarmed" : "xiyang-boji",
                    "dodge"   : "xiyang-boji",
                    "parry"   : "xiyang-jian",
                    "force"   : "jidao-shaqi",
                ]),
]),
([
    "faction" : "Ѳ��",
    "name"    : "��¬������",
    "code"    : "butou",
    "weapon"  : "unarmed",
    "gender"  : "male",
    "no_list" : 1,
    "m_skill" : ([
                    "unarmed" : "huluhezhi-shou",
                    "dodge"   : "yixingbu",
                    "parry"   : "huluhezhi-shou",
                    "force"   : "hujiahuwei-gong",
                ]),
]),
});

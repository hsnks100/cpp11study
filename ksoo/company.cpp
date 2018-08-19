#include <iostream>
#include <memory>
#include <vector>
class Particle
{
    public:
    Particle(int nID)
    {
        m_nID = nID;
        std::cout << "Particle " << m_nID << "번 생성. " << std::endl;
    }
    ~Particle()
    {
        std::cout << "파괴" << std::endl;
    }
    int m_nID;
    std::shared_ptr<Particle> m_Other;
};
int circularReference()
{
    std::shared_ptr<Particle> ParticlePtr1(new Particle(1));
    {
        std::shared_ptr<Particle> ParticlePtr2(new Particle(2));
        ParticlePtr1 -> m_Other = ParticlePtr2;
        ParticlePtr2 -> m_Other = ParticlePtr1;
        std::cout << "ParticlePtr1의 ID: " << ParticlePtr1 -> m_nID << std::endl;
        std::cout << "ParticlePtr2의 ID: " << ParticlePtr2 -> m_nID << std::endl;
    }
    std::cout << "ParticlePtr1의 ID: " << ParticlePtr1->m_nID << std::endl;
    return 0;
}
int main()
{
    {
        std::unique_ptr<Particle> ParticlePtr(new Particle(1));
    }
    std::unique_ptr<Particle> ParticlePtr1(new Particle(11));
    std::vector<std::unique_ptr<Particle>> ParticlePtrs;
    std::cout << "컨테이너 ParticlePtrs에 ParticlePtr1 넣기" << std::endl;
    // ParticlePtrs.push_back(ParticlePtr1); // 컴파일 에러
    ParticlePtrs.push_back(std::move(ParticlePtr1));
    if(ParticlePtr1.get() == nullptr)
    {
        std::cout << "ParticlePtr1에서 관리하는 객체 없음" << std::endl;
    }
    return 0;
}

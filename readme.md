# WebServer 프로젝트

이 프로젝트는 Boost.Asio를 사용하여 C++로 구현한 간단한 웹 서버입니다. 빌드 도구로 CMake를 사용합니다.

## 주요 기능
- HTTP 요청을 처리합니다.
- 간단한 HTML 응답을 반환합니다.
- 비동기 네트워킹을 위해 **Boost.Asio**를 활용합니다.

---

## 요구 사항
1. **VCPKG**: C++ 의존성 관리 도구.
2. **Boost**: 비동기 입출력(IO) 라이브러리.
3. **CMake**: 빌드 시스템 생성 도구.
4. **Git**: 버전 관리 도구.

---

## 설치 방법

### 1. 저장소 복제
```bash
git clone https://github.com/nichul/webserver.git
cd webserver

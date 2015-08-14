
class AutoLocker
{
public:
	AutoLocker(LPCRITICAL_SECTION pCritical)
		:m_pCritical(pCritical)
	{
		if(m_pCritical)
			EnterCriticalSection(m_pCritical);
	}
	~AutoLocker()
	{
		if(m_pCritical)
			LeaveCriticalSection(m_pCritical);
	}
private:
	LPCRITICAL_SECTION		m_pCritical;
};

// example: AutoLocker locker(&m_csLock);
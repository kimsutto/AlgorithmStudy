def solution(brown, red):
    b=(brown+4)/2
    c=brown+red
    
    return [(b+(b**2-4*c)**0.5)/2,(b-(b**2-4*c)**0.5)/2]

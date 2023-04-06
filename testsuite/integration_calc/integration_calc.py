import subprocess

def test_calculator():
    test_cases = [
        ("2+2\n", 4),
        ("3*4-1\n", 11),
        ("(1+2)*(3-4)\n", -3),
        ("2^3\n", 8)
    ]

    for test_case in test_cases:
        input_str, expected_output = test_case
        
        proc = subprocess.Popen(
            ["../../bin/calculator"],
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True
        )
        
        stdout, stderr = proc.communicate(input_str)
        
        assert stdout.strip() == str(expected_output)

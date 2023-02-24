class WasRun:
    def __init__(self, name):
        self.was_run = None

    def test_method(self):
        self.was_run = 1

    def run(self):
        self.test_method()


test = WasRun("testMethod")
print(test.was_run)
test.run()
print(test.was_run)